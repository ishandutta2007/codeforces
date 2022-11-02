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

#define MN 300005
#define ML 21
int n, q;
int a[MN];
int nxt[MN][ML];
int cur[ML];
int dp[MN][ML];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(nxt, 0x3f, sizeof nxt);
    memset(dp, 0x3f, sizeof dp);
    memset(cur, 0x3f, sizeof cur);

    cin >> n >> q;
    F0R(i, n){
        cin >> a[i];
    }
    RFOR(i, n-1, 0){
        F0R(j, 20){
            //dp[i][j] = nxt[i][j] = cur[j];
            //dp[i][j] = cur[j]; nxt[i][j] = cur[j];
            if(a[i] & (1<<j)){
                //dp[i][j] = cur[j] = i;
                //dp[i][j] = i; cur[j] = i;
                dp[i][j] = i;
                nxt[i][j] = cur[j];
                cur[j] = i;
            }
        }
    }
    RFOR(i, n-1, 0){
        F0R(j, 20){
            if(nxt[i][j] == INF) continue;
            F0R(k, 20){
                dp[i][k] = min(dp[i][k], dp[nxt[i][j]][k]);
            }
        }
    }

    /*F0R(i, n){
        F0R(j, 20){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    F0R(_, q){
        int x, y;
        cin >> x >> y;
        --x; --y;
        bool ok = false;
        F0R(i, 20){
            if((a[y] & 1<<i) && dp[x][i] <= y){
                ok = true;
                break;
            }
        }
        if(ok){
            cout << "Shi\n";
        } else{
            cout << "Fou\n";
        }
    }

    return 0;
}