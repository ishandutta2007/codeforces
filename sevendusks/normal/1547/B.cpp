#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int T,t[30];
char s[30];
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
		scanf("%s",s+1);
		int n=strlen(s+1);
		int l,r;
		for (int i=1;i<=n;i++) if (s[i]=='a') l=r=i;
		memset(t,0,sizeof(t));
		for (int i=1;i<=n;i++) t[s[i]-'a']++;
		bool bl=1;
		for (int i=0;i<n;i++) if (t[i]!=1) bl=0;
		for (int i=1;i<n;i++)
		{
			if (l>1&&s[l-1]=='a'+i) l--;
			else if (r<n&&s[r+1]=='a'+i) r++;
			else bl=0;
		}
		if (l!=1||r!=n) bl=0;
		if (bl) puts("YES");
		else puts("NO");
	}
}