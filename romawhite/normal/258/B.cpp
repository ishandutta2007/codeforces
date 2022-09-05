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
#include <stack>
using namespace std;

#define y1 rsfds
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod=1000000007;

LL cnt[10];

int dp[10][10];
vector<int> a;
int main(){
    int m;
    cin >> m;
    int l = 0;
    int m1 = m;
    while (m1){
          a.PB(m1 % 10);
          m1 /= 10;
          ++l;      
    }
    reverse(ALL(a));
    dp[0][0] = 1;
    
    FOR(i,1,10)
               FOR(j,0,i + 1){
                         dp[i][j] += 8 * dp[i - 1][j];
                         if (j) dp[i][j] += 2 * dp[i - 1][j - 1];          
               }
    int c = 0;
    FOR(pref,0,l){
                 FOR(j , 0, a[pref]){
                      int c1 = c;
                      if (j == 4 || j == 7) ++c1;
                      FOR(t,0,10)
                                 cnt[c1 + t] += dp[l - pref - 1][t];
                      }
                 if (a[pref] == 4 || a[pref] == 7) ++c;
    }
    cnt[c]++;
    cnt[0]--;
    
    int t[10];
    
    LL res = 0;
    FOR(i1,0,10)
    FOR(i2,0,i1)
    FOR(i3,0,i1)
    FOR(i4,0,i1)
    FOR(i5,0,i1)
    FOR(i6,0,i1)
    FOR(i7,0,i1)
                if (i1 > i2 + i3 + i4 + i5 + i6 + i7){
                 CLEAR(t);
                 LL add = 1;
                 add *= cnt[i1];
                 
                 add *= cnt[i2] - t[i2];
                 add %= mod;
                 t[i2]++;
                 
                 add *= cnt[i3] - t[i3];
                 add %= mod;
                 t[i3]++;
                 
                 add *= cnt[i4] - t[i4];
                 add %= mod;
                 t[i4]++;
                 
                 add *= cnt[i5] - t[i5];
                 add %= mod;
                 t[i5]++;
                 
                 add *= cnt[i6] - t[i6];
                 add %= mod;
                 t[i6]++;
                 
                 add *= cnt[i7] - t[i7];
                 add %= mod;
                 t[i7]++;
                 res = (res + add) % mod;
    }
    cout << res << endl;
    cin.get();cin.get();
    return 0;
}