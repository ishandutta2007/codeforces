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

#define MN 15
#define MM 2005
int t;
int n, m;
int gr[MN][MM];
pii mx[MM];
int gr2[MN][MN];

int gr3[MN][MN];
int bleh[MN];
int mxs[MN];
int calc(int lv){
    if(lv == min(m, 4)){
        memset(mxs, 0, sizeof mxs);
        F0R(i, n){
            F0R(j, min(m, 4)){
                gr3[i][j] = gr2[(i+bleh[j])%n][j];
                mxs[i] = max(mxs[i], gr3[i][j]);
                //cout << gr3[i][j] << " ";
            }
            //cout << "\n";
        }
        int sm = 0;
        F0R(i, n){
            sm += mxs[i];
            //cout << mxs[i] << " ";
        }
        //cout << "\n";
        return sm;
    }
    //cout << "doing " << lv << "\n";
    int ans = 0;
    F0R(i, n){
        bleh[lv] = i;
        ans = max(ans, calc(lv+1));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n >> m;
        F0R(i, n){
            F0R(j, m){
                cin >> gr[i][j];
                mx[j].f = max(mx[j].f, gr[i][j]);
                mx[j].s = j;
            }
        }
        sort(mx, mx+m, greater<pii>() );
        F0R(i, min(m, 4)){
            F0R(j, n){
                gr2[j][i] = gr[j][mx[i].s];
            }
        }
        /*F0R(i, n){
            F0R(j, min(m, 4)){
                cout << gr2[i][j] << " ";
            }
            cout << "\n";
        }*/
        cout << calc(1) << "\n";
        F0R(i, m) mx[i] = mp(0, 0);
    }
    
    return 0;
}