#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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

#define MN 10005
#define MK 1005
int n, m;
int d[MN];
int g, r;

int amt[MN][MK];
vi chk[MK]; //for this cycle, all possibles at a certain time

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, m) cin >> d[i];
    cin >> g >> r;
    sort(d, d+m);

    memset(amt, 0x3f, sizeof amt);

    amt[0][0] = 0;
    chk[0].pb(0);
    bool ok = true;
    int ccnt = 0;
    while(ok){
        ok = false;
        F0R(ct, g){
            for(auto u : chk[ct]){
                if(u == m-1){
                    cout << ct+1LL*(g+r)*ccnt << "\n";
                    return 0;
                }
                if(u != 0 && ct+d[u]-d[u-1] <= g){
                    int nt = ct+d[u]-d[u-1];
                    if(amt[u-1][nt] == INF){
                        amt[u-1][nt] = ccnt;
                        chk[nt].pb(u-1);
                    }
                }
                if(ct+d[u+1]-d[u] <= g){
                    int nt = ct+d[u+1]-d[u];
                    if(amt[u+1][nt] == INF){
                        amt[u+1][nt] = ccnt;
                        chk[nt].pb(u+1);
                    }
                }
            }
            chk[ct].clear();
        }
        for(auto u : chk[g]){
            if(u == m-1){
                cout << 1LL*(g+r)*ccnt+g << "\n";
                return 0;
            }
            if(amt[u][0] == INF){
                amt[u][0] = ccnt+1;
                ok = true;
                chk[0].pb(u);
            }
        }
        ++ccnt;
    }
    cout << "-1\n";    
    return 0;
}