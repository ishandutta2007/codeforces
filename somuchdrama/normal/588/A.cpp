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
    
    int n;
    cin >> n;
    ll mn = 101;
    ll ans = 0;
    rep(i,0,n){
    	ll a, p;
    	cin>> a >> p;
    	mn = min(mn, p);
    	ans += a * mn;
    }

    cout << ans << '\n';

    
       

    return 0;
}