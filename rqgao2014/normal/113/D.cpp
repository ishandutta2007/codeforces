#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#define pb push_back
using namespace std;

const double eps=0.00000000001;

vector<int> g[30];
struct mat{
    int x,y;
    double a[600][600];
};
mat operator * (const mat &a,const mat &b){
    mat tmp;
    memset(tmp.a,0,sizeof(tmp.a));
    tmp.x=a.x;
    tmp.y=b.y;
     for(int i=1;i<=a.x;i++)
        for(int j=1;j<=a.y;j++)
            if(a.a[i][j]>eps){
                for(int k=1;k<=b.y;k++)
                    tmp.a[i][k]+=a.a[i][j]*b.a[j][k];
            }
    return tmp;
}
int n,m,a,b,match[30][30],tot,d[30];
mat t,fir;  
double p[30];   

int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        d[x]++,d[y]++;
        g[x].pb(y),g[y].pb(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%lf",&p[i]),g[i].pb(i);
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n;j++)
            match[i][j]=++tot;
    t.x=tot,t.y=tot; 
    fir.x=tot;fir.y=1;
    if(a==b) fir.a[match[n+1][a]][1]=1.0;
    fir.a[match[a][b]][1]=1.0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<g[i].size();k++)
                for(int l=0;l<g[j].size();l++){
                    int u=g[i][k],v=g[j][l];
                    if(u==v) continue;
                    double k1,k2;
                    if(u==i) k1=p[i]; else k1=(1.0-p[u])/(double)(d[u]);
                    if(v==j) k2=p[j]; else k2=(1.0-p[v])/(double)(d[v]);
                    t.a[match[i][j]][match[u][v]]+=k1*k2;
                }
    
    for(int i=1;i<=n;i++)
    {
        t.a[match[n+1][i]][match[n+1][i]]=1.0;
        for(int j=1;j<=tot;j++)
            t.a[match[n+1][i]][j]+=t.a[match[i][i]][j];
    }
    for(int i=1;i<=18;i++){ 
        t=t*t;
        /*for(int k=1;k<=tot;k++)
        {
            for(int j=1;j<=tot;j++)
                printf("%.5f ",t.a[k][j]);
            puts("");
        }
        puts(""); */
    }
    fir=t*fir;
    for(int i=1;i<=n;i++) printf("%.9lf ",fir.a[match[n+1][i]][1]);
    return 0;
}