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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const ll INF=200000000000ll;
const ll mod=1000000007;

    int a = 0;
    int n,u,r;
    int *st,xr[35],p[35];
    ll k[35];
    ll res;
ll result(int * t){
    ll rr = 0;
    FOR(i,0,n)
       rr += (ll)t[i]*k[i];
    return rr;
}



void f(int * t){
     if (a >= u) return;
     int *tt = new int[35];
     a++;
     
     FOR(i,0,n)
               tt[i] = t[p[i]] + r;
     if ((u - a) % 2 == 0)
        res = max(res,result(tt));
     f(tt);
     a--;
     if ((u - a) % 2 == 1){
        FOR(i,0,n)
                  tt[i] = t[i]^xr[i];
        res = max(res,result(tt));
     
     }
     if (a+2<=u){
    a += 2;
     FOR(i,0,n)
                  t[i] = t[i] ^ xr[i];
     FOR(i,0,n)
               tt[i] = t[p[i]] + r;
     if ((u - a)%2 == 0)
         res = max(res,result(tt));
     f(tt);
     FOR(i,0,n)
                  t[i] = t[i] ^ xr[i];
     a -= 2;
     }
      delete[] tt;
}


int main(){
    st = new int[35];
   /* a[1].PB(0);
    b[1].PB(1);
    a[2].PB(2);
    FOR(i,1,30)
                FOR(j,0,a[i].size()){
                                     a[i+1].PB(2*a[i][j]);
                                     b[i+1].PB(2*a[i][j] + 1);
                                     if (i < 29)
                                        a[i+2].PB(4*a[i][j] + 2);             
    }
    FOR(i,1,31)
               FOR(j,0,b[i].size())
                                   a[i].PB(b[i][j]);*/

    cin >> n >> u >> r;

    FOR(i,0,n)
              cin >> st[i];
    FOR(i,0,n)
              cin >> xr[i];
    FOR(i,0,n)
              cin >> k[i];
    FOR(i,0,n)
              cin >> p[i];
    FOR(i,0,n)
              p[i]--;
    res = -INF;
    if (u % 2 == 0){
       ll rrr = 0;
       FOR(i,0,n)
                 rrr += (ll)st[i]*k[i];
       res = rrr;      
    }
    f(st);
    cout << res;
    /*int tt[35];
    int s2[35];
    FOR(i,0,35)
               s2[i] = 1<<i;
    for(int change = u; change > 0; change-=2){
            FOR(l,0,a[change].size()){
                                      int t[35];
                                      FOR(i,0,n)
                                                t[i] = st[i];
                                      FOR(i,0,change){
                                                      if(a[change][l] & s2[i]){
                                                                      FOR(i,0,n)
                                                                                t[i] ^= xr[i];}
                                                      else{
                                                           FOR(i,0,n)
                                                                tt[i] = t[p[i]] + r;
                                                           FOR(i,0,n)
                                                                     t[i] = tt[i];
                                                      }
                                                                      
                                      }
                                      int r = 0;
                                      FOR(i,0,n)
                                                r += t[i]*k[i];
                                      res = max(res,r);
    }           
               
}
cout << res;*/
    //system("pause");
    return 0;
}