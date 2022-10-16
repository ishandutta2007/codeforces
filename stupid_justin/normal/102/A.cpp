#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int inf=0x3f3f3f3f;
int m,n;
int pr[N];
bool a[N][N];
int ans;
int main()
{
    cin>>n>>m;
    ans=inf;
    for(int i=1;i<=n;i++) cin>>pr[i];
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][k] && a[k][j] && a[i][j])
                {
                    ans=min(ans,pr[i]+pr[j]+pr[k]);
                }
    if (ans<inf)
    cout<<ans<<endl;
    else 
    cout<<-1<<endl;
}