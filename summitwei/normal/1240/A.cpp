#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
ll p[MN];
ll x, a, y, b;
ll k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    F0R(_, q){
        cin >> n;
        F0R(i, n){
            cin >> p[i];
        }
        sort(p, p+n, greater<ll>());
        cin >> x >> a >> y >> b >> k;
        if(x < y){
            swap(a, b);
            swap(x, y);
        }
        ll lcm = a*b/__gcd(a, b);
        ll l=0, r=n+1;
        while(l+1<r){
            ll mid = (l+r)/2;
            ll cntBoth = mid/lcm;
            ll cntX = mid/a-cntBoth;
            ll cntY = mid/b-cntBoth;
            //cout << cntBoth << " " << cntX << " " << cntY << "\n";
            ll tot = 0;
            FOR(i, 0, cntBoth-1){
                tot += (x+y)*p[i]/100;
            }
            FOR(i, cntBoth, cntBoth+cntX-1){
                tot += x*p[i]/100;
            }
            FOR(i, cntBoth+cntX, cntBoth+cntX+cntY-1){
                tot += y*p[i]/100;
            }
            //cout << mid << " " << tot << "\n";
            if(tot >= k){
                r = mid;
            } else{
                l = mid;
            }
        }
        if(r == n+1){
            cout << "-1\n";
        } else{
            cout << r << "\n";
        }
    }
    
    return 0;
}