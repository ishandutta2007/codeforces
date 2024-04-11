/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,n,a[N],vi[N];
char s[N];
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
		scanf("%s",s+1);
		vector<int> b,r;
		for (int i=1;i<=n;i++)
		{
			 if (s[i]=='B') b.push_back(a[i]);
			 else r.push_back(a[i]);
		}
		sort(b.begin(),b.end());reverse(b.begin(),b.end());
		sort(r.begin(),r.end());reverse(r.begin(),r.end());
		bool bl=1;
		for (int i=1;i<=n;i++)
		{
			if (b.empty())
			{
				if (r.back()>i)
				{
					bl=0;
					break;
				}
				r.pop_back();
			}
			else
			if (r.empty())
			{
				if (b.back()<i){bl=0;break;}
				b.pop_back();
			}
			else
			{
				if (b.back()>=i) b.pop_back();
				else if (r.back()<=i) r.pop_back();
				else{bl=0;break;}
			}
		}
		if (bl) puts("YES");
		else puts("NO");
	}
}