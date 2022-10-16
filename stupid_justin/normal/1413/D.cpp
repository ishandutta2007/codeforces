#include<bits/stdc++.h>
#define NO {puts("NO");return 0;}
#define int long long
#define rd(x) x=read()
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=2e5+5;
int n,cnt;
int a[N],vis[N];
int p,m,q,tmp;
int f[N],l;
char ch;
signed main()
{
    rd(n);
    for (int i=1;i<=n*2;i++)
    {
        cin>>ch;
        if (ch=='+') tmp++,f[++cnt]=tmp,l=0;
        else
        {
            rd(p);
            if (p<=l || cnt<=0) NO
            if (l==0) vis[f[cnt]]=1;
            a[f[cnt]]=p;cnt--;l=p;
        }
    }
    for (int i=n;i>=1;i--)
	{
		if (vis[i]==1) m=0;
		if (m>a[i]) NO
        m=max(m,a[i]);
    }
    puts("YES");
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
}