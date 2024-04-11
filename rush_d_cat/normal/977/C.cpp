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

const int N=200000+10;
const double EPS = 1e-8;
int n,k;
int a[N];
int main(){
    rd(n); rd(k);
    rep(i,1,n) rd(a[i]);
    sort(a+1,a+1+n);
    if (k==0) {
        return !printf("%d\n", a[1]==1?-1:1);
    }
    if (k==n) {
        return !printf("%d\n", a[n]);
    }
    printf("%d\n", a[k]!=a[k+1]?a[k]:-1);
}