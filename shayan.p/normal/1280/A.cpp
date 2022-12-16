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

const int maxn = 4e6 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int x;
	cin >> x;
	string s;
	cin >> s;
	int pt = 0;
	while(sz(s) < x){
	    int l = pt + 1, r = sz(s);
	    for(int j = 0; j < (s[pt]-'1'); j++){
		for(int k = l; k < r; k++)
		    s.PB(s[k]);
	    }
	    pt++;
	}
	int ans = sz(s);
	while(pt < x){
	    ans = (1ll * (ans - pt - 1) * (s[pt]-'0') + pt + 1) %mod;
	    pt++;
	}
	if(ans < 0)
	    ans+= mod;
	cout << ans <<"\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")