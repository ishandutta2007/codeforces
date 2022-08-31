#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int dp[maxn];
int t[maxn];

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int ans[maxn];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		vi cur;
		for (int i = 1; i <= n; i++) {
			int s;
			scanf("%d", &s);
			for (int j = 2; 1ll * j * j <= s; j++)
				while (s % (j * j) == 0)
					s /= (j * j);
			cur.pb(s);
		}
		sort(cur.begin(), cur.end());
		int mx[2] = {0, 0};
		int sm[2] = {0, 0};
		for (int i = 0; i < cur.size(); ) {
			int j = i;
			while (j < cur.size() && cur[i] == cur[j]) j++;
			int tot = j - i;
			chkmax(mx[tot & 1], tot);
			sm[tot & 1] += tot;
			if (cur[i] == 1 && tot % 2)
				sm[0] += tot;
			i = j;
		}
		int q;
		scanf("%d", &q);
		for (int i = 1; i <= q; i++) {
			ll w;
			scanf("%lld", &w);
			int ans = 0;
			if (w >= 1) ans = max(mx[1], sm[0]);
			else ans = max(mx[0], mx[1]);
			printf("%d\n", ans);
		}
	}
 	return 0;
}