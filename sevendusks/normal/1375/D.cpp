/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1100;
int T,n,a[N],t[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int get()
{
	for (int i=1;i<=n;i++) t[a[i]]=1;
	int ans;
	for (int i=0;i<=n;i++) if (!t[i]){ans=i;break;}
	for (int i=1;i<=n;i++) t[a[i]]=0;
	return ans; 
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int pos=1;vector <int> ans;
		while (pos<=n)
		{
			while (pos<=n&&a[pos]==pos-1) pos++;
			if (pos==n+1) break;
			int now=get();
			if (now==n)
			{
				int r=find(a+pos,a+n+1,pos-1)-a;
				assert(r!=n+1);
				a[r]=now;ans.push_back(r);continue;
			}
			a[now+1]=now;ans.push_back(now+1);
		}
		printf("%d\n",len(ans));
		for (int i:ans) printf("%d ",i);
		printf("\n");
	}
}