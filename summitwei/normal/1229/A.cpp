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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 7005
int n;
ll a[MN], b[MN];
map<ll, vector<int> > ree;
ll sm;
vll good;
bool in[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
    }
    F0R(i, n){
        cin >> b[i];
        ree[a[i]].pb(i);
    }
    for(auto u : ree){
        if(u.s.size() == 1) continue;
        good.pb(u.f);
        for(auto v : u.s){
            sm += b[v];
            in[v] = true;
        }
    }
    F0R(i, n) if(!in[i]){
        bool ok = false;
        for(auto u : good){
            if((u & a[i]) == a[i]){
                ok = true;
                //cout << i << " ok via " << u << "\n";
                break;
            }
        }
        if(ok){
            sm += b[i];
        }
    }

    cout << sm << "\n";
    
    return 0;
}