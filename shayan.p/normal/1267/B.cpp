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
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector< pair<char, int> > V;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;
	ll n = s.size();
	int cnt = 1;
	for(int i = 1; i < n; i++){
		if(s[i] != s[i - 1]) V.pb({s[i - 1], cnt}), cnt = 1;
		else cnt ++;
	}
	V.pb({s[n - 1], cnt});
	ll m = V.size();
	if(m%2 == 0) return cout << 0, 0;
	ll mid = m/2;
	if(V[mid].S == 1) return cout << 0, 0;
	for(int i = 1; mid - i >=0;i++){
		if(V[mid - i].F != V[mid + i].F) return cout << 0, 0;
		if(V[mid - i].S + V[mid + i].S < 3) return cout << 0, 0;
	}
	cout << V[mid].S+1;
	return 0;
}