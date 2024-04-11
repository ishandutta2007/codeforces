#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 105
int n, m;
int g[MN][MN];

int cols[MN];
int rows[MN];

int mn = INF;
int res = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> g[i][j];
        }
    }
    
    FOR(r1, 0, 500){
        //cout << "r1 " << r1 << "\n";
        bool good = true;
        FOR(j, 1, m){
            cols[j] = g[1][j]-r1;
            if(cols[j] < 0){
                good = false;
                break;
            }
            //cout << "cols " << j << " is " << cols[j] << "\n";
        }
        if(!good) continue;
        rows[1] = r1;
        FOR(i, 2, n){
            rows[i] = g[i][1]-cols[1];
            //cout << "rows " << i << " is " << rows[i] << "\n";
            if(rows[i] < 0){
                good = false;
                break;
            }
            
            FOR(j, 2, m){
                if(g[i][j] != (rows[i]+cols[j])){
                    //cout << "breaking at " << i << " " << j << "\n";
                    good = false;
                    break;
                }
            }
            if(!good) break;
        }
        
        if(good){
            int sm = 0;
            FOR(i, 1, n) sm += rows[i];
            FOR(j, 1, m) sm += cols[j];
            /*cout << sm << "\n";
            FOR(i, 1, n){
                F0R(_, rows[i]){
                    cout << "row " << i << "\n";
                }
            }
            FOR(j, 1, m){
                F0R(_, cols[j]){
                    cout << "col " << j << "\n";
                }
            }
            return 0;*/
            if(sm < mn){
                mn = sm;
                res = r1;
            }
        }
    }
    
    if(res == -1) cout << "-1\n";
    else{
        FOR(j, 1, m){
            cols[j] = g[1][j]-res;
        }
        rows[1] = res;
        FOR(i, 2, n){
            rows[i] = g[i][1]-cols[1];
        }
        cout << mn << "\n";
        FOR(i, 1, n){
            F0R(_, rows[i]){
                cout << "row " << i << "\n";
            }
        }
        FOR(j, 1, m){
            F0R(_, cols[j]){
                cout << "col " << j << "\n";
            }
        }
        return 0;
    }
    return 0;
}