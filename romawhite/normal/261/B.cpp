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
const int INF=1000000007;
const LL mod= 1000000007;
const double EPS=1e-7;

LL n , t;

LL C[60][60];

int a[60];

LL dp[51][51][52];

int main(){
    //freopen("mirrors.in","r",stdin);freopen("mirrors.out","w",stdout);

    C[0][0] = 1;
    C[1][0] = 1;
    C[1][1] = 1;
    FOR(i,2,60)
        FOR(j,0,i + 1){
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }

    int n;
    cin >> n;
    int s = 0;
    FOR(i,0,n){
        cin >> a[i];
        s += a[i];
        //a[i] = 1;
    }
    int p;
    cin >> p;

    if (s <= p){
        cout << n << endl;
        return 0;
    }

    memset(dp,0,sizeof(dp));
    FOR(i,0,51)
        dp[0][0][i] = 1;

    FOR(i,0,n)
        RFOR(j,i + 1,0)
            RFOR(l,p + 1, 0)
                FOR(k,0,n + 1)
                    if (i != k && l + a[i] <= p){
                        dp[j + 1][l + a[i]][k] += dp[j][l][k];
                    }

    LL b[60];
    CLEAR(b);
    FOR(l,0, p + 1)
        FOR(i,0,n)
            FOR(j,0,n)
                if (l + a[j] > p){
                    b[i] += dp[i][l][j];
                }

    long double res = 0.0;

    /*FOR(i,0,n + 1){
        FOR(l,0,p + 1)
            cout << dp[i][l][n] << ' ';
        cout << endl;
    }

    FOR(i,0,n)
        cout << b[i] << ' ';*/

    FOR(i,0,n)
        res += 1.0 * i *  b[i] / (C[n - 1][i] * n);

    printf("%.6f\n" , (double)res);

    return 0;
}