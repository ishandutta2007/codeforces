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

#define MN 105
int n, m, h;
int row[MN];
int col[MN];
int top[MN][MN];
int res[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> h;
    F0R(i, m){
        cin >> row[i];
    }
    F0R(i, n){
        cin >> col[i];
    }
    F0R(i, n){
        F0R(j, m){
            cin >> top[i][j];
        }
    }

    F0R(i, n){
        F0R(j, m){
            if(!top[i][j]) continue;

            int rres = col[i];
            int cres = row[j];
            res[i][j] = min(rres, cres);
        }
    }

    F0R(i, n){
        F0R(j, m){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}