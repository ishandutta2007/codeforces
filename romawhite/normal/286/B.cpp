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
 


int main(){
    int n;
    cin >> n;
    
    vector<int> a(2 * n);
    
    FOR(i,0,n)
    a[i] = i;
    
    FOR(k,2,n + 1){
              int l = k - 2;
              int t = a[l];
              for(int i = k; i < n; i += k){
                      int tt = a[l + i];
                      a[l + i] = t;
                      t = tt;
                                     
              }
              a[n + l] = t;
              
              if (k == n){
              FOR(i,l + 1,l + n + 1)
                        printf("%d " , a[i] + 1);
              cout << endl;
              }
              
    }
    
    
    getchar();getchar();
    return 0;
}