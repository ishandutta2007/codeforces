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
const int N=100000+10;
int l,w;
int a[N];
LL min(LL x,LL y) {return x<y?x:y;}
int main(){
    rd(l); rd(w);
    rep(i,1,l-1) {
        rd(a[i]),a[i]+=a[i-1];
    }

    LL mn=1e9+7;
    rep(i,w,l-1) mn=min(mn,a[i]-a[i-w]);
    cout<<mn<<endl;
}