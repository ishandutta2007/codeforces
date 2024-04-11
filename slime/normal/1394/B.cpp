//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int fl[10][10][10][10];
vector<pi> ot[maxn];
vector<pi> fr[maxn];
int cnt[10][10];	
int n, m, k;
vi cur;
int ans = 0;
void dfs(int a) {
	if (a == k) {
		bool flag = 1;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				if (fl[i][cur[i]][j][cur[j]]) flag = 0;
		if (flag) ans++;
		return ;
	}
	for (int j = 0; j <= a; j++)
		cur[a] = j, 
		dfs(a + 1);
}
int main() {

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ot[u].pb(mp(w, v));
	}
	for (int i = 1; i <= n; i++) {
		sort(ot[i].begin(), ot[i].end());
		for (int j = 0; j < ot[i].size(); j++)
			fr[ot[i][j].se].pb(mp(ot[i].size() - 1, j));
	}
	for (int i = 1; i <= n; i++) {
		sort(fr[i].begin(), fr[i].end());
		memset(cnt, 0, sizeof(cnt));
		for (auto u : fr[i]) {
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					if (cnt[j][k])
						fl[j][k][u.fi][u.se] = 1;
			cnt[u.fi][u.se]++;		
		}
	}
	cur.resize(k);
	dfs(0);
	cout << ans << endl;
	return 0;
}