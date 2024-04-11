#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+2,p=998244353;
int s[N],b[N];
int n,c,i,t,m,j,k,ans,la;
inline void read(register int &x)
{
	register int c=getchar(),fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
int main()
{
	read(t);
	while (t--)
	{
		c=getchar();n=0;ans=0;
		while (c<'a'||c>'z') c=getchar();
		while (c>='a'&&c<='z') s[++n]=c,c=getchar();
		for (i=2;i<=n;i++)
		{
			if (s[i]==s[i-1]) s[i]=0,++ans;
			else if (s[i]==s[i-2]) s[i]=0,++ans;
		}
		printf("%d\n",ans);
	}
}