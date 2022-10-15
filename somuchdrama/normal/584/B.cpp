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
    srand(time(0));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;
    ll ds = 1, s = 1;
    ll mod = 1e9+7;
    rep(i,0,n) {
    	ds*=27;
    	s*=7;
    	ds%=mod;
    	s%=mod;
    }
    cout << (ds - s + mod) % mod;

    return 0;
}