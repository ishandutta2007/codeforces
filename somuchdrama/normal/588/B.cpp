#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define rep(a,b,c) for(int a=b;a<c;++a)
#define per(a,b,c) for(int a=b;a>c;--a)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main() {
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    ll n;
    cin >> n;
    ll k = n;
    ll ans = 1;
    for (ll i = 2; i * i <= n; ++i) {
    	if (!(k % i)) {
    		ans *= i;
    		while(!(k % i))
    			k /= i;
    	}
    }
    if (k != 1) {
    	ans *= k;
    }
    
    cout << ans << '\n';

    return 0;
}