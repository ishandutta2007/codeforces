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

int dp[27][27]; 

int main(){
    //freopen("INPUT.TXT","r",stdin);
    //freopen("OUT.TXT","w",stdout);
    int n;
    cin >> n;
    memset(dp,0,sizeof(dp));
    FOR(i,0,n){
        char c[10];
        scanf("%s",c);
        string s = c;
        int b = s[0] - 'a';
        int e = s[s.size()-1] - 'a';
        FOR(i,0,26)
            if (dp[i][b] != 0 || i==b)
                dp[i][e] = max( dp[i][e] , dp[i][b] + (int)s.size());
    }
    int res = 0;
    FOR(i,0,26)
        res = max(res,dp[i][i]);
    cout << res;
    return 0;
}