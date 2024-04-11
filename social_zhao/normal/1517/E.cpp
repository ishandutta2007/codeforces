#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}
 
const int N = 2e5 + 5;
int n, a[N], pre[N], suf[N], p2[N], s2[N];
 
void init() {
	for(int i = 0; i <= n + 5; i++) pre[i] = suf[i] = p2[i] = s2[i] = 0;
	pre[1] = p2[1] = a[1];
	for(int i = 1 + 1; i <= n; i++) pre[i] = pre[i - 1] + a[i], p2[i] = p2[i - 2] + a[i];
	suf[n] = s2[n] = a[n];
	for(int i = n - 1; i >= 1; i--) suf[i] = suf[i + 1] + a[i], s2[i] = s2[i + 2] + a[i];
}
 
namespace AllPAllC { int solve() { return 1; } }
namespace HalfPHalfC {
	int solve() {
		int ans = 0;
		for(int i = 1; i < n; i++) ans += suf[i + 1] < pre[i];
		return ans;
	}
} 
namespace CCCP {
	int bin[N], tot;
	
	int calc(int l, int r, int L, int R, int k) { // CP  [l, r] L, RsumC - sumP < k 
		if(r - l + 1 < 2) return 0;
		int mid = (l + r) >> 1, ans = calc(l, mid, L, R, k) + calc(mid + 1, r, L, R, k);
		// Left(sumC - sumP) + Right(sumC - sumP) < k
		// Left(sumC - sumP) < k - Right(sumC - sumP)
		//  mid  P  
		tot = 0;
		for(int i = mid; i > l; i -= 2) {
			int CPl = i - 1, Cr = i - 2;
			int sumC = pre[Cr] - pre[L - 1] + p2[mid - 1] - p2[CPl - 2];
			int sumP = pre[mid] - pre[L - 1] - sumC;
			bin[++tot] = sumC - sumP;
		}
		sort(bin + 1, bin + 1 + tot);
		for(int i = mid + 1; i < r; i += 2) {
			int CPr = i + 1, Pl = i + 2;
			int sumP = suf[Pl] - suf[R + 1] + p2[CPr] - p2[mid];
			int sumC = suf[mid + 1] - suf[R + 1] - sumP;
			ans += lower_bound(bin + 1, bin + 1 + tot, k - (sumC - sumP)) - bin - 1;
		}
		//  mid  C  
		tot = 0;
		for(int i = mid; i >= l; i -= 2) {
			int CPl = i, Cr = i - 1;
			int sumC = pre[Cr] - pre[L - 1] + p2[mid] - p2[CPl - 2];
			int sumP = pre[mid] - pre[L - 1] - sumC;
			bin[++tot] = sumC - sumP;
		}
		sort(bin + 1, bin + 1 + tot);
		for(int i = mid + 1; i <= r; i += 2) {
			int CPr = i, Pl = i + 1;
			int sumP = suf[Pl] - suf[R + 1] + p2[CPr] - p2[mid - 1];
			int sumC = suf[mid + 1] - suf[R + 1] - sumP;
			ans += lower_bound(bin + 1, bin + 1 + tot, k - (sumC - sumP)) - bin - 1;
		}
		return ans;
	}
	
	int solve() {
		int ans = 0;
		ans += calc(1, n, 1, n, 0);
		ans += calc(1, n - 1, 1, n - 1, -a[n]);
		ans += calc(1 + 1, n, 1 + 1, n, a[1]);
		ans += calc(2, n - 1, 2, n - 1, a[1] - a[n]);
		return ans;
	}
}
 
void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	init();
	int ans = 0;
	ans += AllPAllC::solve(); //  P  C 
	ans += HalfPHalfC::solve(); //  P  C 
	ans += CCCP::solve(); // CCCC CPCPCP PPPPP
	printf("%lld\n", ans % 998244353);
}
 
signed main() {
	int T = get();
	while(T--) solve();
	return 0;
}
 
/*
1
6
20908065 600120285 164191625 49959421 517451054 162920537
*/