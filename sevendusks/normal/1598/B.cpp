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
int T,n,a[N][5];
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
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<5;j++) a[i][j]=read();
		}
		bool bl=1;
		for (int i=0;i<5;i++) for (int j=0;j<i;j++)
		{
			int x=0,y=0,z=0,cnt=0;
			for (int k=1;k<=n;k++)
			{
				if (a[k][i]&&a[k][j]) x++;
				else if (!a[k][i]&&a[k][j]) y++;
				else if (a[k][i]&&!a[k][j]) z++;
				else cnt++;
			}
			if (cnt) continue;
			if (z<=n/2&&y<=n/2) bl=0;
		}
		if (bl) printf("No\n");
		else printf("Yes\n");
	}
}