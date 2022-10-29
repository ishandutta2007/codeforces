#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
typedef long long LL;
LL x;
char s[10];
map <LL,set <LL>> st;
map <LL,vector <LL>> vt;
map <LL,bool> mp;
map <LL,LL> mex;

void add()
{
	mp[x]=1;
}

void del()
{
	mp.erase(x);
	vector <LL> &p=vt[x];
	for(auto v:p) st[v].insert(x);
	p.clear();
}

void qry()
{
	if(st.count(x))
	{
		set <LL> &s=st[x];
		while(!s.empty())
		{
			LL ans=*s.begin();
			if(mp.count(ans))
			{
				s.erase(ans);
				vt[ans].pb(x);
			}
			else {printf("%lld\n",ans); return;}
		}
	}
	LL ans=mex[x];
	while(mp.count(ans))
	{
		vt[ans].pb(x);
		ans+=x;
	}
	printf("%lld\n",mex[x]=ans);
}

int main()
{
	int m;
	scanf("%d",&m);
	x=0,add();
	while(m--)
	{
		scanf("%s",s);
		scanf("%lld",&x);
		if(s[0]=='+') add();
		if(s[0]=='-') del();
		if(s[0]=='?') qry();
	}
	return 0;
}