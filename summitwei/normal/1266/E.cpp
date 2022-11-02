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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, q;
ll a[MN];
map<pii, int> mil;
ll cnts[MN];
ll sm;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        sm += a[i];
    }
    cin >> q;
    F0R(_, q){
        int s, t, u;
        cin >> s >> t >> u;
        if(mil[{s, t}] != 0){
            int bd = mil[{s, t}];
            if(cnts[bd] <= a[bd]){
                ++sm;
            }
            --cnts[bd];
        }
        if(u != 0){
            if(cnts[u] < a[u]){
                --sm;
            }
            ++cnts[u];
        }
        mil[{s, t}] = u;
        cout << sm << "\n";
    }
    
    return 0;
}