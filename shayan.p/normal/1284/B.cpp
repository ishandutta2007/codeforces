// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

vector<int> v1, v2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 0; i < n; i++){	
	int s; cin>>s;
	vector<int> vec(s);
	for(int j = 0; j < s; j++)
	    cin >> vec[j];
	bool is = 0;
	for(int j = 1; j < s; j++)
	    is|= vec[j-1] < vec[j];
	if(is)
	    cnt++;
	else
	    v1.PB(vec[0]), v2.PB(vec.back());
    }
    ll ans = 2ll * cnt * sz(v1) + 1ll * cnt * cnt;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    for(auto p : v2){
	ans += sz(v1) - (upper_bound(v1.begin(), v1.end(), p) - v1.begin());
    }

    return cout << ans<< endl,0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")