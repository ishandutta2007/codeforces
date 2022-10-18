/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=250;
int T,n,m;
char s[N],t[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void work(char s[],int &n)
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<n;j++) if (s[j]=='B') swap(s[j],s[j+1]);
	}
	while (1)
	{
		bool bl=1;
		for (int i=1;i<n;i++) if (s[i]==s[i+1])
		{
			bl=0;
			for (int j=i+2;j<=n;j++) s[j-2]=s[j];
			n-=2;break;
		}
		if (bl) break;
	}
	while (1)
	{
		bool bl=1;
		for (int i=1;i<=n-3;i++)
		{
			if (s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='A'&&s[i+3]=='B')
			{
				bl=0;
				for (int j=i+4;j<=n;j++) s[j-4]=s[j];
				n-=4;break;
			}
			if (s[i]=='B'&&s[i+1]=='C'&&s[i+2]=='B'&&s[i+3]=='C')
			{
				bl=0;
				for (int j=i+4;j<=n;j++) s[j-4]=s[j];
				n-=4;break;
			}
		}
		if (bl) break;
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);m=strlen(t+1);
		work(s,n);work(t,m);
		if (n!=m)
		{
			printf("NO\n");
			continue;
		}
		bool bl=1;
		for (int i=1;i<=n;i++) if (s[i]!=t[i]) bl=0;
		if (bl) puts("YES");
		else puts("NO");
	}
}