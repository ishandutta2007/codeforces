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
    if (n % 4 == 2 || n % 4 == 3){
       cout << -1 << endl;
       return 0;      
    }
    
    int l = 0;
    int r = n - 1;
    vector<int> a(n);
    while (r - l > 1){
          a[l] = l + 1;
          a[l + 1] = r;
          a[r] = r - 1;
          a[r - 1] = l;
          l+=2;
          r-=2;      
    }
    
    if (n & 1)
    a[n / 2] = n / 2;
    
    FOR(i,0,n)
              cout << a[i] + 1 << ' ' ;
    cout << endl;
    getchar();getchar();
    return 0;
}