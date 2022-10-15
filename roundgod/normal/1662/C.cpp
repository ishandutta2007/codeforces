#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,k,d[105],G[105][105],L;
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
struct mat{
    int a[205][205];
    void init(){
        for (int i=1;i<=n*2;i++)
            for (int j=1;j<=n*2;j++)
                a[i][j]=0;
    }
}f[14],ans;
mat sub(mat a,mat b){
    mat ret;
    for (int i=1;i<=n*2;i++)
        for (int j=1;j<=n*2;j++)
            ret.a[i][j]=(a.a[i][j]+M-b.a[i][j])%M;
    return ret;
}
mat mul(mat a,mat b){
    mat ret; ret.init();
    for (int i=1;i<=n*2;i++)
        for (int j=1;j<=n*2;j++)
            for (int k=1;k<=n*2;k++)
                add(ret.a[i][j],1ll*a.a[i][k]*b.a[k][j]%M);
    return ret;
}
int main(){
    cin >> n >> m >> L;
    for (int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        d[u]++; d[v]++;
        G[u][v]=G[v][u]=1;
    }
    f[0].init();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f[0].a[i][j]=G[i][j];
    for (int i=1;i<=n;i++)
        f[0].a[i][i+n]=1,f[0].a[i+n][i]=M-d[i]+1;
    for (int i=1;i<=13;i++) f[i]=mul(f[i-1],f[i-1]);
    if (L<2){puts("0");return 0;}
    L-=2; ans=f[1];
    for (int i=1;i<=n;i++) ans.a[i][i]=0;
    for (int i=13;i>=0;i--) if ((L>>i)&1) ans=mul(ans,f[i]);
    int Ans=0;
    for (int i=1;i<=n;i++) add(Ans,ans.a[i][i]);
    cout << Ans << endl;
}