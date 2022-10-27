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

const int N=1000+10;
const double EPS = 1e-8;
int n,m;
int g[N][N],c[N],d[N],cp[N][N];
char s[N];
void dfs(int u){
    //printf("%d %d\n", u, c[u]);
    rep(i,1,n) {
        if(d[i]==n-1) continue;
        if(g[u][i]==1&&c[i]==c[u]){
            printf("No\n");exit(0);
        }
        if(g[u][i]==1&&c[i]==-1){
            c[i]=1-c[u];
            dfs(i);
        }
    }
}
int main(){
    rd(n);rd(m);
    rep(i,1,n) rep(j,1,n) g[i][j]=(i==j)?0:1;
    rep(i,1,m) {
        int u, v; rd(u), rd(v);
        g[u][v]=g[v][u]=0;
        d[u]++, d[v]++;
    }
    memset(c,-1,sizeof(c));
    rep(i,1,n) if(c[i]==-1&&d[i]!=n-1){
        c[i]=0;
        dfs(i);
    }


    rep(i,1,n) {
        if(d[i]==n-1) s[i]='b';
        else s[i] = (c[i]==0)?'a':'c';
    }

    rep(i,1,n){
        rep(j,1,n){
            if(i==j) continue;
            if(g[i][j]==1) {
                if(!( (s[i]=='a'&&s[j]=='c') || (s[i]=='c'&&s[j]=='a') )) {
                    return !printf("No\n");
                }
            }
            if(g[i][j]==0) {
                if(( (s[i]=='a'&&s[j]=='c') || (s[i]=='c'&&s[j]=='a') )) {
                    return !printf("No\n");
                }
            }
        }
    }
    printf("Yes\n");
    printf("%s\n", s+1);
}