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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
ll m[MN];
ll tot[MN];
ll mx[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> m[i];
        mx[i] = max(mx[i-1], m[i]+1);
    }
    tot[n] = mx[n];
    ll sm = 0;
    RFOR(i, n-1, 1){
        tot[i] = max(tot[i+1]-1, mx[i]);
    }
    FOR(i, 1, n){
        sm = sm+tot[i]-m[i]-1;
    }

    cout << sm << "\n";

    return 0;
}