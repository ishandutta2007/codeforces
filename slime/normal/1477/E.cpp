//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
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
struct bit {
	ll d[maxn + 105];
	int lb(int a) {
		return a & -a;
	}
	void ins(int pl, int x) {
		pl++;
		while (pl < maxn + 100)
			d[pl] += x, pl += lb(pl);
	}
	ll q(int pl) {
		pl++;
		ll ans = 0;
		while (pl) {
			ans += d[pl];
			pl -= lb(pl);
		}
		return ans;
	}
	ll q(int l, int r) {
		chkmax(l, 0);
		chkmin(r, maxn + 10);
		return q(r) - q(l - 1);
	}
}s[2];
 
ll calc(int a) {
	ll ans = s[1].q(a, maxn + 50) - 1ll * a * s[0].q(a, maxn + 50);
	return ans;
}
ll sum[2];
int e[2][maxn];
int sz[2];
multiset<int> tot;
multiset<int> us[2];
#define iter multiset<int>::iterator
int main() {
	int q;
	cin >> sz[0] >> sz[1] >> q;
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= sz[i]; j++) {
			scanf("%d", &e[i][j]), 
			sum[i] += e[i][j], 
			us[i].insert(e[i][j]), 
			tot.insert(e[i][j]);
		}
	for (int j = 1; j <= sz[1]; j++)
		s[0].ins(e[1][j], 1), 
		s[1].ins(e[1][j], e[1][j]);
	while (q--) {
		int t, u;
		scanf("%d%d", &t, &u);
		t--;
		if (t <= 1) {
			int to;
			scanf("%d", &to);
			tot.erase(tot.find(e[t][u]));
			us[t].erase(us[t].find(e[t][u]));
			
			sum[t] -= e[t][u];
			
			if (t == 1)
				s[0].ins(e[t][u], -1), 
				s[1].ins(e[t][u], -e[t][u]);
			
			e[t][u] = to;
			
			tot.insert(e[t][u]);
			us[t].insert(e[t][u]);
			sum[t] += e[t][u];
			
			if (t == 1)
				s[0].ins(e[t][u], 1), 
				s[1].ins(e[t][u], e[t][u]);
			
		}
		else {
			//   <= min + k
			int mn = *tot.begin();
			int k = u;
			
			ll ans = -4e18;
			chkmax(ans, sum[0] - 1ll * sz[0] * (mn - k) - (sum[1] - 1ll * sz[1] * (mn - k)));
			
			iter cur = tot.lower_bound(mn + k + 1); 
			if (cur != tot.begin()) {
				cur--;
				int cr = *cur;
				chkmax(ans, (sum[0] - 1ll * sz[0] * (cr - k)) - (sum[1] - 1ll * sz[1] * (cr - k)));
			}
			
			int mx = *(--us[0].end());
			ll dsum = sum[0] - 1ll * sz[0] * mn;
			
			int um = *(--us[1].end());
			
			if (mx > mn + k) {
				chkmax(ans, -calc(mx - k) + dsum - (mx - mn) + k);
				iter h = us[0].lower_bound(um + k);
				if (h != us[0].end()) {
					mx = *h; 
					if (mx > mn + k)
						chkmax(ans, -calc(mx - k) + dsum - (mx - mn) + k);
				}
				if (h != us[0].begin()) {
					h--;
					mx = *h; 
					if (mx > mn + k)
						chkmax(ans, -calc(mx - k) + dsum - (mx - mn) + k);
				}
			}
				
			mx = *(--us[1].end());
			if (mx > mn + k)
				chkmax(ans, -calc(mx - k) + dsum);
			
			printf("%lld\n", ans);
		}
	}
	return 0;
}