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

ll cnt[30];
ll f[30];
void MAIN(){
	memset(cnt, 0, sizeof cnt);
	ll k;
	cin >> k;
	ll m = 0;
	for(int i = 2; i < 30; i++){
		if(!k) break;
		m ++;
		cnt[k%i]++;
		//cerr << k % i << ' ';
		k /= i;
	}
	//cerr << '\n';
	ll ans = 1;
	ll sm = cnt[0];
	for(int i = 1; i <= m; i++){
		sm += cnt[i];
		ans *= (sm - i + 1);
	}
	for(int i= 0; i <20;i ++) ans/= f[cnt[i]];
	if(cnt[0]){
		cnt[0] --;
		ll an = 1;
		ll sm = cnt[0];
		for(int i = 1; i < m; i++){
			sm += cnt[i];
			an *= (sm - i + 1);
		}	
		for(int i= 0; i <20;i ++) an/= f[cnt[i]];
		ans -= an;	
	}
	cout << ans-1 << '\n';
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i <= 20; i++) f[i] = f[i - 1] * i;
	ll T;
	cin >> T;
	while(T--) MAIN();
	return 0;
}

/*
3
1
11
123456

*/