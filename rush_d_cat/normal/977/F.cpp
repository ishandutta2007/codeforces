#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
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
int n,a[N];

map<int,int> mp,pos,pr;
int main(){
    rd(n);
    rep(i,1,n) rd(a[i]);

    rep(i,1,n) {
        pos[a[i]] = i;
        pr[i] = pos[a[i]-1];
        if(mp[a[i]-1]+1>mp[a[i]]) {
            mp[a[i]]=mp[a[i]-1]+1;
        }
    }
    int mx=0,now=0;
    for(int i=1;i<=n;i++) {
        if(mp[a[i]]>mx) {
            mx=mp[a[i]], now=pos[a[i]]; 
        }
    }
    vector<int> ret; 
    while(now) {    
        ret.pb(now);
        now = pr[now];
    }
    printf("%d\n", sz(ret));
    for(int i=sz(ret)-1;i>=0;i--)
        printf("%d ", ret[i]);
}