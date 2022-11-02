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
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 155
int n;
vi ans[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ans[0].pb(1);
    ans[1].pb(0); ans[1].pb(1);
    FOR(i, 2, n){
        ans[i].resize(i+1);
        FOR(j, 1, i){
            ans[i][j] += ans[i-1][j-1];
        }
        FOR(j, 0, i-2){
            ans[i][j] += ans[i-2][j];
        }
        FOR(j, 0, i){
            ans[i][j] %= 2;
        }
    }
    cout << ans[n].size()-1 << "\n";
    for(auto u : ans[n]) cout << u << " ";
    cout << "\n" << ans[n-1].size()-1 << "\n";
    for(auto u : ans[n-1]) cout << u << " ";
    cout << "\n";

    return 0;
}