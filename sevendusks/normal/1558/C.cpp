/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2510;
int t,n,a[N];
vector <int> ans;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void add(int x)
{
	reverse(a+1,a+1+x);
	ans.push_back(x);
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		bool bl=1;
		for (int i=1;i<=n;i++) if ((i&1)!=(a[i]&1)) bl=0;
		if (!bl)
		{
			printf("-1\n");
			continue;
		}
		ans.clear();
		bl=1;
		while (n>1)
		{
			int x,y;
			for (int i=1;i<=n;i++)
			{
				if (a[i]==n) x=i;
				if (a[i]==n-1) y=i;
			}
			if (x==y+1)
			{
				add(x);
				add(n);
			}
			else if (x==y-1)
			{
				add(y+1);
				add(3);
				add(n);
			}
			else if (x<y)
			{
				add(x);
				add(y-1);
				add(y+1);
				add(3);
				add(n);
			}
			else
			{
				add(x);
				for (int i=1;i<=n;i++) if (a[i]==n-1) y=i;
				add(y-1);
				add(y+1);
				add(3);
				add(n);
			}
			n-=2;
		}
		if (!bl) continue;
		for (int i=1;i<=n;i++) assert(a[i]==i);
		printf("%d\n",len(ans));
		for (int i:ans) printf("%d ",i);
		printf("\n");
	}
}