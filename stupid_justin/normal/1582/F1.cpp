#include<bits/stdc++.h>
#define rd(x) x=read()
using namespace std;
int read(){int x=0,f=1;char c=getchar();while (c<'0' || c>'9') {if (c=='-') f=-1;c=getchar();}while (c>='0' && c<='9') x=x*10+c-'0',c=getchar();return x*f;}
const int N=5005;
const int M=8200;
int n;
bool a[N][M];
bool hav[N][M];
int tag[N][M];
int cnt[N];
bool vis[M];
vector<int> ans;
signed main()
{
    rd(n);for (int i=0;i<=5000;i++) a[i][0]=1;
    for (int i=0;i<=5000;i++) tag[i][++cnt[i]]=i,hav[i][i]=1;
    for (int i=1,x;i<=n;i++)
    {
        rd(x);
        for (int i=1;i<=cnt[x];i++)
        {
            int t=tag[x][i];
            if (!a[x][t]) a[x][t]=1;
            for (int j=x+1;j<=5000;j++)
            {
                if (hav[j][j^t]) break;
                tag[j][++cnt[j]]=j^t;
                hav[j][j^t]=1;
            }
        }
        cnt[x]=0;
    }
    for (int i=1;i<=5000;i++) for (int j=0;j<=8191;j++) if (a[i][j]) vis[j]=1;
    for (int i=0;i<=8191;i++) if (vis[i]) ans.push_back(i);
    cout<<ans.size()<<"\n";
    for (int x:ans) cout<<x<<" ";cout<<"\n";

}