#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define rd(x) scanf("%d",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)

const int N=300000+10;
const double EPS = 1e-8;

int n;
double f[N][102],g[N],p[N];

int main(){
    rd(n); rep(i,1,n) scanf("%lf",&p[i]), p[i]/=100.0;
    
    rep(i,1,n) f[n][i] = p[i];
    
    rep(i,n+1,N-1) {
        double mx = 0; int bst = -1;
        rep(j,1,n) {
            double tmp = (1-f[i-1][j])*p[j]/f[i-1][j];
            if (tmp > mx) {
                mx=tmp, bst = j;
            }
        } 
        rep(j,1,n) f[i][j]=f[i-1][j];
        f[i][bst]=(1-f[i-1][bst])*p[bst] + f[i-1][bst];


    }

    double res = 0;
    rep(i,n,N-1) {
        g[i]=1;
        rep(j,1,n) g[i]*=f[i][j]; 
        res=res+i*(g[i]-g[i-1]);
    }
    printf("%.5f\n", res);

}