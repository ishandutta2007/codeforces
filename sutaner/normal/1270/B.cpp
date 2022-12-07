#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 500019
#define ll long long int 
using namespace std;

const int inf = 2000000019;

int n;
int a[maxn];

int ans1, ans2;
bool solve(int l, int r){
	int mid = ((r - l) >> 1) + l;
	if (l == r) return false; 
	if (solve(l, mid)) return true;
	if (solve(mid + 1, r)) return true;
	int mx = -2, mx2 = 0;
	per(i, mid, l) if (a[i] - (mid - i + 1) > mx) mx = a[i] - (mid - i + 1), mx2 = i;
	int mi = inf, mi2 = 0;
	rep(i, mid + 1, r) if (a[i] + (i - mid) < mi) mi = a[i] + (i - mid), mi2 = i;
	if (mx >= mi) {ans1 = min(mx2, mi2), ans2 = max(mx2, mi2); return true;}
	
	mx = -2, mx2 = 0;
	rep(i, mid + 1, r) if (a[i] - (i - mid) > mx) mx = a[i] - (i - mid), mx2 = i;
	mi = inf, mi2 = 0;
	per(i, mid, l) if (a[i] + (mid - i + 1) < mi) mi = a[i] + (mid - i + 1), mi2 = i;
	if (mx >= mi) {ans1 = min(mx2, mi2), ans2 = max(mx2, mi2); return true;}
	
	return false;
}

int main(){
	//#ifndef ONLINE_JUDGE
	//	freopen("B.in", "r", stdin);
	//#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		if (solve(1, n)) printf("YES\n%d %d\n", ans1, ans2);
		else printf("NO\n");
	}
	return 0;
}