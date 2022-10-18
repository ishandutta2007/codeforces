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
int T,n,a[N],t[N];
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
		memset(t,0,sizeof(t));
		n=read();
		for (int i=1;i<=n;i++) t[abs(read())]++;
		int ans=(t[0]>0);
		for (int i=1;i<=100;i++)
		{
			if (t[i]==1) ans++;
			else if (t[i]>1) ans+=2;
		}
		printf("%d\n",ans);
	}
}