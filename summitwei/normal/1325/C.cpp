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
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
vi e[MN];
pii a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        a[i] = {u, v};
    }
    int mx = 1;
    FOR(i, 1, n){
        if(e[i].size() > e[mx].size()){
            mx = i;
        }
    }
    if(e[mx].size() == 2){
        F0R(i, n-1){
            cout << i << "\n";
        }
    } else{
        int cur = 3;
        int ot = 0;
        F0R(i, n-1){
            if(a[i].f == mx || a[i].s == mx){
                if(ot < 3){
                    cout << ot << "\n";
                    ++ot;
                } else{
                    cout << cur << "\n";
                    ++cur;
                }
            } else{
                cout << cur << "\n";
                ++cur;
            }
        }
    }

    return 0;
}