#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const signed N=1e6+5;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int n,m,x;
int a[N];
int b[N];
int c[N];
int ans[N];
int can[N];
int flag,CAN;
vector<int> cnt[N];
signed main()
{
	int T;rd(T);
	while(T--)
	{
		rd(n);rd(m);
		flag=0;CAN=1;
		for (int i=1;i<=n;i++) rd(a[i]);
		for (int i=1;i<=n;i++) rd(b[i]);
		for (int i=1;i<=m;i++) rd(c[i]);
		for (int i=1;i<=n;i++) can[i]=0;
		for (int i=1;i<=n;i++) cnt[i].clear();
		for (int i=1;i<=n;i++) if (a[i]!=b[i]) cnt[b[i]].push_back(i);
		for (int i=1;i<=n;i++) can[b[i]]=1;
		for (int i=m;i>=1;i--)
		{
			if (!can[c[i]] && !flag)
			{
				CAN=0;
				break;
			}
			if (cnt[c[i]].size())
			{
				ans[i]=cnt[c[i]][cnt[c[i]].size()-1];
				cnt[c[i]].pop_back();
				flag=ans[i];
				continue;
			}
			if (!flag) 
			{
				for (int j=1;j<=n;j++) if (c[i]==b[j]) flag=j;
			}
			ans[i]=flag;
		}
		for (int i=1;i<=n;i++) if (cnt[i].size()) CAN=0;
		if (!CAN) puts("NO");
		else 
		{
			puts("YES");
			for (int i=1;i<=m;i++) cout<<ans[i]<<" ";puts("");
		}
	}
	
}