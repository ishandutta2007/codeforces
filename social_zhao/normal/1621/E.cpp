#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int n, m, sumP[N], sumM[N], sumS[N];
int a[N], k[N], sum[N], id[N], rev[N];
double tmp[N];
vector<int> b[N], ans[N];

int GetP(int l, int r) { if(l > r) return 0; return sumP[r] - sumP[l - 1]; }
int GetM(int l, int r) { if(l > r) return 0; return sumM[r] - sumM[l - 1]; }
int GetS(int l, int r) { if(l > r) return 0; return sumS[l] - sumS[r + 1]; }

void solve() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= m; i++) a[i] = a[i + n - m];
	for(int i = 1; i <= m; i++) {
		b[i].clear(), ans[i].clear();
		k[i] = get(), sum[i] = 0;
		for(int j = 1, u; j <= k[i]; j++) u = get(), b[i].emplace_back(u), sum[i] += u;
	}
	for(int i = 1; i <= m; i++) id[i] = i;
	sort(id + 1, id + 1 + m, [](int x, int y) { return sum[x] * k[y] < sum[y] * k[x]; });
	for(int i = 1, g; i <= m; i++) rev[id[i]] = i, g = __gcd(sum[id[i]], k[id[i]]), tmp[i] = 1.0 * (sum[id[i]] / g) / (k[id[i]] / g);
	for(int i = 0; i <= m + 5; i++) sumP[i] = sumM[i] = sumS[i] = 0;
	for(int i = 2; i <= m; i++) sumP[i] = sumP[i - 1] + (sum[id[i]] > a[i - 1] * k[id[i]]);
	for(int i = 1; i <= m; i++) sumM[i] = sumM[i - 1] + (sum[id[i]] > a[i] * k[id[i]]);
	for(int i = m - 1; i >= 1; i--) sumS[i] = sumS[i + 1] + (sum[id[i]] > a[i + 1] * k[id[i]]);
	for(int i = 1; i <= m; i++) {
		int now = rev[i];
		for(auto v : b[i]) {
			int sn = sum[i] - v, sb = k[i] - 1;
			int g = __gcd(sn, sb);
			sn /= g, sb /= g;
			double sze = 1.0 * sn / sb;
			int pos = lower_bound(tmp + 1, tmp + 1 + m, 1.0 * sn / sb) - tmp;			
			if(pos == now) cout << (GetM(1, now - 1) == 0 && sze <= a[now] && GetM(now + 1, m) == 0);
			else if(pos < now) cout << (GetM(1, pos - 1) == 0 && sze <= a[pos] && GetS(pos, now - 1) == 0 && GetM(now + 1, m) == 0);
			else cout << (GetM(1, now - 1) == 0 && GetP(now + 1, pos - 1) == 0 && sze <= a[pos - 1] && GetM(pos, m) == 0); 
		}
	}
	cout << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}