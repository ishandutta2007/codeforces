//#pragma comment(linker,"/STACK:16777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <fstream>
#include <memory.h>

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
typedef long double ld;

const double pi=3.141592653589793;
const int INF=2000000000;

int m=0;


    int dp[110][11000];
int main(){
    int n,m,k,l;
    vector<int> a[110];
    cin >> n >> m;
    FOR(i,0,n){
        cin >> k;
        FOR(j,0,k){
            cin >> l;
            a[i].PB(l);
        }
    }
    int b[110][110];
    memset(b,0,sizeof(b));
    FOR(i,0,n){
        int c[110];
        int d[110];
        c[0]=0;
        FOR(j,1,a[i].size()+1)
            c[j] = c[j-1]+a[i][j-1];
        d[0]=0;
        FOR(j,1,a[i].size()+1)
            d[j] = d[j-1]+a[i][a[i].size()-j];
        FOR(j,0,a[i].size()+1)
            FOR(t,0,j+1)
                b[i][j] = max(b[i][j],c[t]+d[j-t]);
    }

    FOR(i,0,110)
        FOR(j,0,11000)
            dp[i][j]=0;
    FOR(i,0,a[0].size()+1)
        dp[0][i]=b[0][i];
    FOR(i,1,n)
        FOR(j,0,11000)
            FOR(tt,0,a[i].size()+1)
                if (tt<=j)
                    dp[i][j] = max(dp[i][j],dp[i-1][j-tt] + b[i][tt]);
    cout << dp[n-1][m];
    return 0;
}