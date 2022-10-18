/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=3*1e5+100;
int T,n,a[N],pos[N];
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
		for (int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
		int l=1,r=n;set <int> s;bool bl=1;
		for (int i=1;i<=n;i++) s.insert(i);
		while (l<r)
		{
			if (a[*s.begin()]==r){bl=0;break;}
			if (a[*s.rbegin()]==l){bl=0;break;}
			if (a[*s.begin()]==l) break;
			if (a[*s.rbegin()]==r) break;
			auto it=s.lower_bound(pos[r]);
			s.erase(it);r--;
		}
		if (bl) puts("YES");
		else puts("NO");
	}
}