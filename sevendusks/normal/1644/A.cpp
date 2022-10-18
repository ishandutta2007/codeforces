/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int T;
char s[10];
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
		scanf("%s",s);
		int t[3];t[0]=t[1]=t[2]=0;bool bl=1;
		for (int i=0;i<6;i++)
		{
			if (s[i]=='R'||s[i]=='B'||s[i]=='G')
			{
				if (s[i]=='R'&&!t[0]) bl=0;
				if (s[i]=='B'&&!t[1]) bl=0;
				if (s[i]=='G'&&!t[2]) bl=0;
			}
			else
			{
				if (s[i]=='r') t[0]=1;
				if (s[i]=='b') t[1]=1;
				if (s[i]=='g') t[2]=1;
			}
		}
		if (bl) printf("YES\n");
		else printf("NO\n");
	}
}