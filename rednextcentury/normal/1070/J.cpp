#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 30010

int n, m, k;
int T = 1;
ll cnt[26];
int vis[N][26];
ll memo[N][26];

ll dp(ll needR, ll needC, int i, int tot){
	int can = k - tot;
	if (needR <= 0){
		if (can >= needC) return 0;
		return 1e18;
	}
	if (needC <= 0){
		if (can >= needR) return 0;
		return 1e18;
	}
	if (i == 26)  return needR * needC;

	ll &ret = memo[needR][i];
	if (vis[needR][i] == T) return ret;
	vis[needR][i] = T;

	ll c1 = dp(needR - cnt[i], needC, i + 1, tot + cnt[i]);
	ll c2 = dp(needR, needC - cnt[i], i + 1, tot + cnt[i]);
	return ret = min(c1, c2);
}

int main(){
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		string s; cin >> s;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < k; i++){
			int id = s[i] - 'A';
			cnt[id]++;
		}
		T++;
		ll ans = dp(n, m, 0, 0);
		for (int i = 0; i < 26; i++){
			ll prv = cnt[i];
			cnt[i] = 0;
			T++;
			ans = min(ans, dp(n, m, 0, 0));
			cnt[i] = prv;
		}
		cout << ans << endl;
	}

	return 0;
}