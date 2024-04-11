#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n;
int r[MN];
int c[MN];
vector<pair<pii, pii> > aah;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> r[i];
    }
    FOR(i, 1, n){
        cin >> c[i];
    }

    FOR(i, 1, n){
        int rv, cv;
        FOR(j, 1, n){
            if(r[j] == i){
                rv = j;
            }
            if(c[j] == i){
                cv = j;
            }
        }
        swap(r[rv], r[i]);
        swap(c[cv], c[i]);
        if(rv != i || cv != i) aah.pb({{rv, i}, {i, cv}});
    }

    cout << aah.size() << "\n";
    for(auto u : aah){
        cout << u.f.f << " " << u.f.s << " " << u.s.f << " " << u.s.s << "\n";
    }

    return 0;
}