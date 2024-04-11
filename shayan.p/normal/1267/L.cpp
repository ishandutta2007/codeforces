#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll cnt[30], c2[30];
ll ans[Maxn];
ll n, l, k;
bool check(ll x){
	
	for(int i = 0; i < 30; i++) c2[i] = cnt[i];
	
	ll rem = k - 1;
	for(int i = 0; i < x; i++){
		c2[ans[i]] --;
		
		if(c2[ans[i]] == -1) return false;
		
		for(int j = 0; j < ans[i]; j++){
			ll d = min(rem, c2[j]);
			rem -= d;
			c2[j] -= d;
		}
		c2[ans[i]] -= rem;
		if(c2[ans[i]] < 0) return false;
	}
	return true;
}

ll o[Maxn][Maxn];


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//ll n, l, k;
	cin >> n >> l >> k;
	
	str s;
	cin >> s;
	for(auto x : s) cnt[x-'a'] ++;
	memset(o, -1, sizeof o);
	
	fill(ans, ans + Maxn, 25);
	str res = "";
	for(int i = 0; i < l; i++){
		ll ind = 25;
		for(int c = 0; c < 26; c++){
			ans[i] = c;
			if(check(i + 1)) break;
		}
		res += ('a' + ans[i]);
		o[k][i] = ans[i];
		//cout << ans[i] << ' ';
	}
	//cout << '\n';
	
	
	ll rem = k - 1;
	for(int i = 0; i < l; i++){
		cnt[ans[i]] --;
		o[k][i] = ans[i];
		for(int j = 0; j < ans[i]; j++){
			ll d = min(rem, cnt[j]);
			for(int jj = 0; jj < d; jj++) o[k - rem + jj][i] = j;
			rem -= d;
			cnt[j] -= d;
		}
		cnt[ans[i]] -= rem;
		for(int j = 1; j <= rem; j++) o[k - j][i] = ans[i];
	}
	
	rem = n - k;
	for(int i = 0; i < l; i++){
		//cnt[ans[i]] --;
		//o[k][i] = ans[i];
		for(int j = 25; j > ans[i]; j--){
			ll d = min(rem, cnt[j]);
			for(int jj = 0; jj < d; jj++) o[k + rem - jj][i] = j;
			rem -= d;
			cnt[j] -= d;
		}
		cnt[ans[i]] -= rem;
		for(int j = 1; j <= rem; j++) o[k + j][i] = ans[i];
	}
	
	
	//for(int i = 0; i < 6; i++) cout << cnt[i] << ' ';
	//cout << '\n';
	ll p = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < l; j++){
			if(o[i][j] == -1){
				while(cnt[p] == 0) p++;
				o[i][j] = p;
				cnt[p]--;
			}
			cout << ((char)(o[i][j] + 'a'));
			//cout << o[i][j] << ' ';
		}
		cout << '\n';
	}
	//cout << res << '\n';
	return 0;
}
/*
3 2 2
abcdef


2 3 1
abcabc
*/