/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int t,n,k,a[N],b[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();k=read();
		for (int i=1;i<=n;i++) a[i]=b[i]=read();
		sort(b+1,b+1+n);
		unordered_map <int,int> mp;
		for (int i=1;i<=n;i++) mp[b[i]]=i;
		for (int i=1;i<=n;i++) a[i]=mp[a[i]];
		int cnt=n;
		for (int i=1;i<n;i++) if (a[i]==a[i+1]-1) cnt--;
		if (cnt<=k) puts("Yes");
		else puts("No");
	}
}