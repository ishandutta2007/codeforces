#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,w,z[1000],px[55][55][111],py[55][55][111];ll x[1000],y[1000],f[55][55][111];
vector<int> p,q;
int main()
{
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1;i<=m;i++)cin>>x[i]>>y[i]>>z[i];
    memset(px,-1,sizeof px);
    memset(py,-1,sizeof py);
    for(int i=1;i<=m;i++)
        for(int j=0;j<=y[i]-x[i];j++)px[1][i][j]=0,py[1][i][j]=0,f[1][i][j]=x[i]+j;
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<=100;k++)if(px[i][j][k]!=-1)
            {
                ll ne=x[j]+k+w;
                ll ff=f[i][j][k]+ne;
                for(int l=1;l<=m;l++)
                    if(z[l]>z[j]&&x[l]<=ne&&ne<=y[l])
                        if(ff>f[i+1][l][ne-x[l]])
                            f[i+1][l][ne-x[l]]=ff,
                            px[i+1][l][ne-x[l]]=j,
                            py[i+1][l][ne-x[l]]=k;
                ne=(x[j]+k)*w,ff=f[i][j][k]+ne;
                for(int l=1;l<=m;l++)
                    if(z[l]>z[j]&&x[l]<=ne&&ne<=y[l])
                        if(ff>f[i+1][l][ne-x[l]])
                            f[i+1][l][ne-x[l]]=ff,
                            px[i+1][l][ne-x[l]]=j,
                            py[i+1][l][ne-x[l]]=k;
            }
    int si=-1,sj=-1;
    for(int i=1;i<=m;i++)
        for(int j=0;j<=y[i]-x[i];j++)
            if(px[n][i][j]!=-1)
                if(si==-1||f[n][si][sj]<f[n][i][j])si=i,sj=j;
    if(si==-1){puts("NO");return 0;}
    for(int k=n;k>=1;k--)
    {
        p.push_back(si),q.push_back(sj);
        int i1=px[k][si][sj],j1=py[k][si][sj];
        si=i1,sj=j1;
    }
    reverse(p.begin(),p.end());
    reverse(q.begin(),q.end());
    puts("YES");
    for(int k=0;k<n;k++)cout<<p[k]<<" "<<x[p[k]]+q[k]<<endl;
    return 0;
}