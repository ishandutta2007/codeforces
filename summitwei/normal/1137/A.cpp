#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

#define MN 1005
int n, m;
int grid[MN][MN];
int gtrn[MN][MN];
int horiz[MN][MN];
int vert[MN][MN];
int unhor[MN];
int unver[MN];
vi vals;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, n){
        F0R(j, m){
            cin >> grid[i][j];
            gtrn[j][i] = grid[i][j];
        }
    }

    F0R(i, n){
        vals.clear();
        F0R(j, m){
            vals.pb(grid[i][j]);
        }
        sort(vals.begin(), vals.end());
        vi::iterator it = unique(vals.begin(), vals.end());

        vals.resize(distance(vals.begin(), it));

        F0R(j, m){
            horiz[i][j] = lower_bound(vals.begin(), vals.end(), grid[i][j])-vals.begin();
        }
        unhor[i] = vals.size();
        //cout << vals.size() << "\n";
    }
    F0R(j, m){
        vals.clear();
        F0R(i, n){
            vals.pb(grid[i][j]);
        }
        sort(vals.begin(), vals.end());
        vi::iterator it = unique(vals.begin(), vals.end());

        vals.resize(distance(vals.begin(), it));

        F0R(i, n){
            vert[i][j] = lower_bound(vals.begin(), vals.end(), grid[i][j])-vals.begin();
        }
        unver[j] = vals.size();
        //cout << vals.size() << "\n";
    }

    /*F0R(i, n){
        F0R(j, m){
            cout << horiz[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    F0R(i, n){
        F0R(j, m){
            cout << vert[i][j] << " ";
        }
        cout << "\n";
    }*/

    F0R(i, n){
        F0R(j, m){
            int b4 = max(vert[i][j], horiz[i][j]);
            int aft = max(unhor[i]-horiz[i][j], unver[j]-vert[i][j]);

            cout << b4 + aft << " ";
        }
        cout << "\n";
    }

    return 0;
}