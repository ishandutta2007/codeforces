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

LL bpow(LL a,int k){
   if (k == 0) return 1;
   if (k & 1) return (a * bpow(a,k - 1)) % mod;
   return bpow((a*a) % mod, k / 2);           
}
 
LL c[2007];
int a[2007];
LL res[2007];
int main(){
    int n;
    LL k;
    cin >> n >> k;
    FOR(i,0,n)
              cin >> a[i];
    if (!k){
       FOR(i,0,n)
                 cout << a[i] << ' ';
       //system("pause");
       return 0;        
    }
    c[0] = 1;
    FOR(i,1,n){
              c[i] = c[i - 1];
              c[i] = (c[i] * (k + LL(i) - 1)) % mod;
              c[i] = (c[i] * bpow(i , mod - 2)) % mod;          
    }
    //FOR(i,0,n)
    //          c[i] = c[i + 1];
    //FOR(i,0,n)
    //          cout << c[i] << ' ';
    FOR(i,0,n){
               res[i] = 0;
               FOR(j,0,i + 1)
                         res[i] = (res[i] + a[j] * c[i - j]) % mod;           
    }
    FOR(i,0,n)
              cout << res[i] << ' ';
    //system("pause");
    return 0;
}