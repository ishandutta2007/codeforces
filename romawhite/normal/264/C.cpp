//#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <time.h>
#include <sstream>
using namespace std;

#define next gdfsgvd
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define FILL(a,value) memset(a,value,sizeof(a))

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const double pi = acos(-1.0);
const LL INF=1000000000;
const LL mod= 1000000007;
const double EPS=1e-7;

LL v[100007];
int c[100007];

LL dp[100007];

int main(){
    //freopen("mirrors.in","r",stdin);freopen("mirrors.out","w",stdout);
    
    int n , q;
    cin >> n >> q;

    FOR(i,0,n)
        cin >> v[i];
    FOR(i,0,n)
        cin >> c[i];

    FOR(test,0,q){
        LL a,b;
        cin >> a >> b;
        FOR(i,0,100007)
            dp[i] = -1ll * INF * INF;
        LL M1 = -1ll * INF * INF;
        LL M2 = -1ll * INF * INF;

        FOR(i,0,n){
            bool w = (M1 == dp[c[i]]);
            LL k;
            if (w) k = M2;
            else k = M1;
            if (k < 0) k = 0;
            if (dp[c[i]] != -1ll * INF * INF)
                dp[c[i]] = max(dp[c[i]] , dp[c[i]] + a * v[i]);
            dp[c[i]] = max(dp[c[i]] , k + b * v[i]);

            if (w){
                M1 = dp[c[i]];
            }
            else{
                if (dp[c[i]] > M1){
                    M2 = M1;
                    M1 = dp[c[i]];
                }
                else if (dp[c[i]] > M2)
                    M2 = dp[c[i]];
            }

        }

        LL res = 0;
        FOR(i,0,100007)
            res = max(res , dp[i]);

        cout << res << endl;


    }

    return 0;
}