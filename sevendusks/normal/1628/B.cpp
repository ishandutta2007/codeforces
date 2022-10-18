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
int T,n;
string s[N];
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
		for (int i=1;i<=n;i++) cin>>s[i];
		auto ck=[&](string a)
		{
			if (len(a)==1) return true;
			return a[0]==a.back();
		};
		if (any_of(s+1,s+1+n,ck))
		{
			printf("YES\n");
			continue;
		}
		map <string,int> mp[4];
		mp[2].clear();mp[3].clear();
		auto ck1=[&](string a)
		{
			reverse(a.begin(),a.end());
			if (mp[len(a)].count(a)) return true;
			return false;
		};
		bool bl=0;
		for (int i=1;i<=n;i++)
		{
			if (ck1(s[i])) bl=1;
			mp[len(s[i])][s[i]]=1;
		}
		mp[2].clear();mp[3].clear();
		for (int i=1;i<=n;i++)
		{
			if (len(s[i])==3)
			{
				string now;now.push_back(s[i][1]);now.push_back(s[i][0]);
				mp[2][now]=1;
				now.clear();now.push_back(s[i][2]);now.push_back(s[i][1]);
				if (mp[3].count(now)) bl=1;
			}
			else
			{
				if (mp[2].count(s[i])) bl=1;
				mp[3][s[i]]=1;
			}
		}
		if (bl) printf("YES\n");
		else printf("NO\n");
	}
}