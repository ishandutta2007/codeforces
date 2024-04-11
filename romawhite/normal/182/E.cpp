#pragma comment(linker, "/STACK:32777216")
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
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;
const ll mod=1000000007;

ll dp[3002][105][105];
//ll dp1[3002][105];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,l;
    cin >> n >> l;
    int a[105];
    int b[105];
    FOR(i,0,n)
        cin >> a[i] >> b[i];
    CLEAR(dp);
    FOR(i,0,105)
        FOR(j,0,105)
            dp[0][i][j] = 1;
    FOR(i,1,l+1)
        FOR(j,0,n){
            if (i>=a[j]){
                if (i == a[j]) dp[i][j][b[j]] = 1;
                else
                FOR(t,0,n)
                    if (t!=j)
                        dp[i][j][b[j]] = (dp[i][j][b[j]] + dp[i-a[j]][t][a[j]]) % mod;
            }
            if (a[j]!=b[j])
                if (i>=b[j]){
                    if (i == b[j]) dp[i][j][a[j]] = 1;
                    else
                    FOR(t,0,n)
                        if (t!=j)
                            dp[i][j][a[j]] = (dp[i][j][a[j]] + dp[i-b[j]][t][b[j]]) % mod;
                }
    }
    ll res = 0;
    /*FOR(i,0,5){
        FOR(j,0,5)
            cout << dp[1][i][j] << ' ';
        cout << endl;
    }*/
    FOR(i,0,105)
        FOR(j,0,105)
            res = (res + dp[l][i][j]) % mod;
    cout << res << endl;
    return 0;
}