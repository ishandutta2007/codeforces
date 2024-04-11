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
 
map<int,int> M;

int main(){
   int n;
   cin >> n;
   int res = 0;
   FOR(i,0,n){
              int a;
              cin >> a;
              if (!a) continue;
              M[a]++;
              if (M[a] > 2){
                 cout << -1 << endl;
                 return 0;         
              }           
              if (M[a] == 2) ++res;
   } 
   cout << res << endl;
    return 0;
}