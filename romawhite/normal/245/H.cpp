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
#include <stack>
#include <sstream>
#include <fstream>

 
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
#define SZ(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod = 1000000007;

int g[5007][5007];
int dp[5007][5007];

int sz[5007];

int main() {
    
    string s;
    cin >> s;

    FOR(i,0,s.size()){
        g[i][sz[i]++] = i;
        int j = 1;
        while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]){
            g[i + j][sz[i + j]++] = i - j;
            ++j;
        }
    }
    FOR(i,0,s.size()){
        int j = 1;
        while (i - j + 1 >= 0 && i + j < s.size() && s[i - j + 1] == s[i + j]){
            g[i + j][sz[i + j]++] = i - j + 1;
            ++j;
        }
    }

    FOR(i,0,s.size())
        sort(g[i],g[i] + sz[i]);

    CLEAR(dp);

    FOR(len,0,s.size())
        FOR(l,0,s.size())
            if (l + len < s.size()){
                int r = l + len;
                if (l == r)
                    dp[l][r] = 1;
                else{
                    int L = 0;
                    int R = sz[r] - 1;
                    while (R - L > 1){
                        int X = (L + R) / 2;
                        if (g[r][X] >= l) R = X;
                        else L = X;
                    }
                    dp[l][r] = dp[l][r - 1];
                    if (g[r][R] >= l){
                        if (g[r][L] >= l) R = L;
                        dp[l][r] += sz[r] - R;
                    }
                }
            }

    int q;
    cin >> q;
    FOR(i,0,q){
        int l,r;
        scanf("%d%d",&l,&r);
        --l;--r;
        printf("%d\n",dp[l][r]);
    }

    return 0;
}