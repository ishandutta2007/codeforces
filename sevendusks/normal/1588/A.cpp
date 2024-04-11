/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=110;
int T,n,a[N],b[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) b[i]=read();
		sort(a+1,a+1+n);sort(b+1,b+1+n);
		unordered_map <int,int> mp;
		for (int i=1;i<=n;i++) mp[a[i]]++;
		bool bl=1;
		for (int i=1;i<=n;i++)
		{
			if (mp.count(b[i]-1)&&mp[b[i]-1]>0) mp[b[i]-1]--;
			else if (mp.count(b[i])&&mp[b[i]]>0) mp[b[i]]--;
			else bl=0;
		}
		if (bl) puts("YES");
		else puts("NO");
	}
}