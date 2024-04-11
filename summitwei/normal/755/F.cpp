#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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

#define MN 1000005
#define SQRT 200
int n, k;
int p[MN];
int vis[MN];
vi cyc;
int cnt[MN];
int t;
void dfs(int cn){
    //cout << "at " << cn << "\n";
    if(vis[cn]){
        cyc.pb(t-vis[cn]);
        ++cnt[t-vis[cn]];
        return;
    }
    vis[cn] = t++;
    dfs(p[cn]);
}

bitset<MN> bleh;
int cnts[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 1, n){
        cin >> p[i];
    }

    t = 1;
    FOR(i, 1, n){
        if(vis[i] == 0) dfs(i);
    }

    sort(cyc.begin(), cyc.end());
    /*for(auto u : cyc){
        cout << u << "\n";
    }*/
    
    int bd = 0;
    for(auto u : cyc){
        bd += u/2;
    }
    bd = min(bd, k);
    int mx = min(n, bd+k);

    bleh[0] = true;
    FOR(i, 2, n){
        if(cnt[i] == 0) continue;
        if(i < SQRT){
            memset(cnts, 0, sizeof cnts);
            FOR(j, i, n){
                if(!bleh[j] && bleh[j-i] && cnts[j-i] < cnt[i]){
                    bleh[j] = true;
                    cnts[j] = cnts[j-i]+1;
                }
            }
        } else{
            F0R(_, cnt[i]){
                bleh |= (bleh<<i);
            }
        }
    }

    int mn;
    if(bleh[k]) mn = k;
    else mn = k+1;

    cout << mn << " " << mx << "\n";

    return 0;
}