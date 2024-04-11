#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=2000000000;
const int mod=1000000007;
const int N=50005;
ll dp[N][505];
int p[N];
   int n,k;
   vector<int> g[N];
   bool used[N];
   ll res = 0;
void dfs (int v) {
    dp[v][0] = 1;
    used[v]=1;
    bool q=0;
    ll t=0;
    for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
        if (used[*i] == 0){
                dfs (*i);
                FOR(j,1,k+1)
                        dp[v][j] += dp[*i][j-1];
                for(int j=1;j<k;j++)
                    t+=dp[*i][j-1]*dp[*i][k-1-j];
        }
        res-=t/2;
        //if (v==1) cout << endl << res << endl;
        t=0;
    for(int j=0;j<=k;j++)
            t+=dp[v][j]*dp[v][k-j];
    res+=t/2;
    //if (v==1) cout << endl << t << endl;
    //res+=dp[v][k];
    //cout << v << ' ' << res << endl;
}
int main() {
   memset(dp,0,sizeof(dp));
   cin >> n >> k;
   memset(p,-1,sizeof(p));
   memset(used,0,sizeof(used));
   FOR(i,0,n-1){
       int a,b;
       cin >> a >> b;
       g[a-1].PB(b-1);
       g[b-1].PB(a-1);
   }
    dfs(0);
    //cout << dp[1][1] << endl << endl;
    cout << res;
    /*FOR(i,0,5){
        FOR(j,0,4)
            cout << dp[i][j] << ' ';
        cout << endl;
    }*/
   return 0;
}