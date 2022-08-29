#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fuckshb
#define y1 fuckhel
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=605,inf=1e9+2*N;
int n,m;
int to[N],tmp[N],s[N][N];
bool in[N];
vector<pr>g[N];
int main(){
    scanf("%d%d",&n,&m);
    rep(i,m){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        g[x].pb(mp(y,z));
    }
    rep(i,n){
        rep(j,n)to[j]=inf,in[j]=0;
        to[i]=0;
        rep(tim,n){
           int mi=0;
            rep(j,n)if(in[mi]||(!in[j]&&to[j]<to[mi]))mi=j;
            rep(j,n)tmp[j]=inf;
            for(pr p:g[mi])tmp[(p.st+to[mi])%n]=to[mi]+p.nd;
            rep(j,n)tmp[j]=min(tmp[j],tmp[(j+n-1)%n]+1);
            rep(j,n)tmp[j]=min(tmp[j],tmp[(j+n-1)%n]+1);
            rep(j,n)to[j]=min(to[j],tmp[j]);
            in[mi]=1; 
        }
        rep(j,n)s[i][j]=to[j];
    }
    rep(i,n)rep(j,n)printf("%d%c",s[i][j]," \n"[j+1==n]);
    return 0;
}