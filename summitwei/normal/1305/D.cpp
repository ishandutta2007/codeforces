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
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n;
vi e[MN];
int d[MN];
queue<int> ree;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        ++d[u];
        ++d[v];
    }
    FOR(i, 1, n){
        if(d[i] == 1) ree.push(i);
    }
    while(ree.size() > 1){
        int fs = ree.front();
        ree.pop();
        int sc = ree.front();
        ree.pop();
        --d[fs]; --d[sc];
        cout << "? " << fs << " " << sc << endl;
        cout.flush();
        int resp;
        cin >> resp;
        if(resp == fs){
            cout << "! " << fs << endl;
            return 0;
        } else if(resp == sc){
            cout << "! " << sc << endl;
            return 0;
        } else{
            for(auto nn : e[fs]){
                if(d[nn] != 0) --d[nn];
                if(d[nn] == 1) ree.push(nn);
            }
            for(auto nn : e[sc]){
                if(d[nn] != 0) --d[nn];
                if(d[nn] == 1) ree.push(nn);
            }
        }
    }

    cout << "! " << ree.front() << endl;

    return 0;
}