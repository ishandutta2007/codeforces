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

int a[100007];

LL bpow(LL a,int k){
   if (k == 0) return 1;
   if (k & 1) return (a * bpow(a , k - 1)) % mod;
   return bpow ( (a * a) % mod , k / 2);           
}

int main(){
   int n;
   cin >> n;
   FOR(i,0,n)
             cin >> a[i];
   sort(a , a + n);
   int b[200];
   LL res = 0;
   FOR(i,1,a[n - 1] + 1){
                int d = 0;
                for (int j = 1; j * j <= i; ++j)
                    if (i % j == 0){
                       if (j * j == i) ++d;
                       else d += 2;      
                    }   
                CLEAR(b);         
                int j;
                int t = 0;
                for(j = 1; j * j <= i; ++j)
                      if (i % j == 0){
                         if (a[0] >= j){
                            b[t++] = 0;         
                         }      
                         else{
                         int L = 0;
                         int R = n - 1;
                         while (R - L > 1){
                               int X = (L + R) / 2;
                               if (a[X] >= j) R = X;
                               else L = X;     
                         }
                         if (a[R] < j) L = R;
 
                         b[t++] = L + 1;
                         }
                         if (j * j != i){
                               if (a[0] >= i/j){
                                    b[t++] = 0;
                                    continue;         
                                 }      
                                 int L = 0;
                                 int R = n - 1;
                                 while (R - L > 1){
                                       int X = (L + R) / 2;
                                       if (a[X] >= i/j) R = X;
                                       else L = X;     
                                 }
                                 if (a[R] < i/j) L = R;
                                 b[t++] = L + 1;
                               
                         }
                      }
                sort(b,b + d);
                /*cout <<i << endl;
                FOR(j,0,d)
                          cout << b[j] << ' ';
                cout << endl;*/
                LL add = 1;
                b[d] = n;
                FOR(j,0,d){
                    int j1 = 0;
                    while (j1 < d && b[j + j1 + 1] == b[j]) ++j1;
                    LL wer = 0;
                    wer +=  bpow ( j + j1 + 1 , b[j + j1 + 1] - b[j]);
                    if (j + j1 + 1 == d){
                         wer -= bpow(j + j1 , b[j + j1 +1] - b[j]);
                         wer = (wer + mod) % mod;      
                    }               
                    add = (add * wer ) % mod;
                    j += j1;
                }
                res = (res + add) % mod;
   }
   cout << res << endl;
   cin.get();cin.get();
   return 0;
}