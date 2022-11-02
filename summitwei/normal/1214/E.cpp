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
pii d[MN];
int l;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> d[i].f;
        d[i].s = 2*i-1;
    }
    sort(d+1, d+n+1, greater<pii>() );

    l = n;

    FOR(i, 1, n){
        if(i != n) cout << d[i].s << " " << d[i+1].s << "\n";
        int loc = d[i].f+i-1;
        if(loc == l){
            d[l+1] = {0, d[i].s+1};
            ++l;
        }
        cout << d[i].s+1 << " " << d[loc].s << "\n";
    }
    
    return 0;
}