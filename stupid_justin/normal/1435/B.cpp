#include <bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=5e3+5;
int ans[N][N];
int T,n,m,num;
map<int,int> Map;
signed main()
{
    rd(T);
    while (T--)
    {
        Map.clear();
        rd(n);rd(m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                rd(num);
                Map[num]=j;
            }
        for (int j=1;j<=m;j++)
            for (int i=1;i<=n;i++)
            {
                rd(num);
                ans[i][Map[num]]=num;
            }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++) printf("%lld ",ans[i][j]);
            printf("\n");
        }
    }
}