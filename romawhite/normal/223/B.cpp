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
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const double pi=3.141592653589793;
const int INF=1000000000;
const int mod=1000000007;
 
string a,b;
 
int dp[200007];
int dpr[200007];

vector<int> g[26];

int main(){
    cin >> a >> b;
    if (a[0] == b[0]) dp[0] = 1;
    else dp[0] = 0;
    FOR(i,1,a.size()){
           dp[i] = dp[i - 1];
           if (dp[i] == b.size()){
              FOR(j,i + 1,a.size())
                      dp[j] = b.size();
              break;          
           } 
           if (a[i] == b[dp[i]]) dp[i]++;
           if (dp[i] == b.size()){
              FOR(j,i + 1,a.size())
                      dp[j] = b.size();
              break;          
           }                             
    }
    if (dp[a.size() - 1] != b.size()){
       cout << "No\n";
       //system("pause");
       return 0;                
    }
    
    if (a[a.size() - 1] == b[b.size() - 1]) dpr[a.size() - 1] = b.size() - 2;
    else dpr[a.size() - 1] = b.size() - 1;
    RFOR(i,a.size() - 1,0){
           dpr[i] = dpr[i + 1];
           if (dpr[i] == -1){
              RFOR(j,i,0)
                      dpr[j] = -1;
              break;          
           }  
           if (a[i] == b[dpr[i]]) dpr[i]--;
           if (dpr[i] == -1){
              RFOR(j,i,0)
                      dpr[j] = -1;
              break;          
           }                             
    }
    
    /*FOR(i,0,a.size())
                     cout << dp[i] << ' ';
    cout << endl;
    FOR(i,0,a.size())
                     cout << dpr[i] << ' ' ;
    cout << endl;*/
    
    FOR(i,0,b.size())
                     g[b[i] - 'a'].PB(i);
    
    bool ans = 1;
    if (a[0] != b[0]) ans = 0;
    if (a[a.size() - 1] != b[b.size() - 1]) ans = 0;
    FOR(i,1,a.size() - 1){
                        int l = dpr[i + 1];
                        int r = dp[i - 1];
                        //cout << l << ' ' << r << endl;
                        int c = a[i] - 'a';
                        if (l > r || g[c].empty() || g[c][0] > r || g[c][g[c].size() - 1] < l){
                           ans = 0;
                           break;      
                        } 
                        
                        int L = 0;
                        int R = g[c].size() - 1;
                        while (R - L > 1){
                              int x = (L + R) / 2;
                              if (g[c][x] >= l) R = x;
                              else L = x;      
                        }
                        
                        if (!((g[c][L] >= l && g[c][L] <= r) || (g[c][R] >= l && g[c][R] <= r))) ans = 0;                                      
    }
    if (ans) cout << "Yes";
    else cout << "No";
    //system("pause");
    return 0;
}