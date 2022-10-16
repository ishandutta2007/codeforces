#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e5+5;
const int M=6e6+6;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int n,ans,m,x,y;
int a[N],b[N];
vector<int> p[N];
int pre[N],suf[N];
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
    {
        ans=0;
        rd(n);for (int i=1;i<=n;i++) rd(a[i]),b[i]=a[i];
        sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b;
        for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
        for (int i=0;i<=m+2;i++) p[i].clear();
        for (int i=1;i<=n;i++) p[a[i]].push_back(i);
        for (int i=0;i<=m+2;i++)
        {
            int sz=p[i].size();if (sz==0 || sz==1) continue;
            x=0;
            for (int j=0;j<sz;j++)
            {
                ans+=x*(n-p[i][j]+1);
                x+=p[i][j];
            }

        }
        cout<<ans<<endl;

    }
}
/*
00 00 00 00 00 00 00
01 01 01 01
*/