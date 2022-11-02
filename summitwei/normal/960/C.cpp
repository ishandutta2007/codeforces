#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 3005
ll x, d;
vll ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> d;
    ll cv = 1;
    while(x > 0){
        ll cur = 1;
        int amt = 1;
        while(2*cur+1 <= x){
            cur = 2*cur+1;
            ++amt;
        }
        F0R(_, amt) ans.pb(cv);
        x -= cur;
        cv += (d+1);
    }

    cout << ans.size() << "\n";
    for(auto u : ans) cout << u << " ";
    cout << "\n";

    return 0;
}