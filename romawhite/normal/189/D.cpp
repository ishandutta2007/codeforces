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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;
const ll mod=200907;
const ll N = 1100;
int d[65][65][65];

int w[65][65][65];
int w1[65][65][65];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,r;
    cin >> n >> m >> r;
    FOR(k,0,m)
        FOR(i,0,n)
            FOR(j,0,n)
                cin >> d[k][i][j];
    FOR(t,0,65)
    FOR(i,0,65)
        FOR(j,0,65)
            w[t][i][j] = INF;
    FOR(t,0,m){
        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    d[t][i][j] = min (d[t][i][j], d[t][i][k] + d[t][k][j]);
        FOR(i,0,n)
            FOR(j,0,n)
                w[0][i][j] = min(w[0][i][j] , d[t][i][j]);
    }

    FOR(t,1,61)
        FOR(i,0,n)
            FOR(j,0,n){
                w[t][i][j] = w[t-1][i][j];
                FOR(k,0,n){
                    w[t][i][j] = min(w[t][i][j],w[t-1][i][k] + w[0][k][j]);
                    w[t][i][j] = min(w[t][i][j],w[0][i][k] + w[t-1][k][j]);
                }
    }
    
    FOR(i,0,r){
        int a,b,t;
        cin >> a >> b >> t;
        a--;
        b--;
        if (t > 60) t = 60;
        cout << w[t][a][b] << endl;
    }
    return 0;
}