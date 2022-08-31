#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, ll>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int n, m;
ll a[maxn];
stack<int> r[2];
ll otp[maxn][3], cnt = 0;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u] += w, a[v] -= w;		
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) continue;
		int tp;
		if (a[i] > 0) tp = 0;
		else tp = 1;
		a[i] = abs(a[i]);
		while (a[i] && !r[tp ^ 1].empty()) {
			int eid = r[tp ^ 1].top();
			ll mn = min(a[eid], a[i]);
			a[eid] -= mn, a[i] -= mn;
			if (tp == 0) otp[cnt][0] = i, otp[cnt][1] = eid, otp[cnt++][2] = mn;
			else otp[cnt][0] = eid, otp[cnt][1] = i, otp[cnt++][2] = mn;
			if (a[eid] == 0)
				r[tp ^ 1].pop();
		}
		if (a[i]) r[tp].push(i);
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		printf("%lld %lld %lld\n", otp[i][0], otp[i][1], otp[i][2]);
	return 0;
}

/*
3
4 3
10 160 70 50
70 111 111 0
1 2
2 3
3 4
2 1
143 420
214 349
2 1
4 3
10 160 70 50
70 111 111 0
1 2
2 3
3 4
*/