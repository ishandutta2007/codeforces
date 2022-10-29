#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=200005;
int n;
multiset <int> s1,s2;
vector <int> v1,v2;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int get(int x)
{
	if(!x) return 0;
	return get(x/10)+1;
}

void solve()
{
	n=getint();
	s1.clear();
	s2.clear();
	v1.clear();
	v2.clear();
	rep(i,1,n) s1.insert(getint());
	rep(i,1,n)
	{
		int x=getint();
		if(s1.find(x)!=s1.end())
			s1.erase(s1.find(x));
		else v1.pb(x);
	}
	int ans=0;
	for(auto x:s1)
	{
		if(x>9) s2.insert(get(x)),++ans;
		else s2.insert(x);
	}
	for(auto i:v1)
	{
		int x=i;
		if(x>9) x=get(x),++ans;
		if(s2.find(x)!=s2.end())
			s2.erase(s2.find(x));
		else v2.pb(x);
	}
	int jdg=0;
	for(auto x:s2) if(x==1) ++jdg;
	for(auto x:v2) if(x==1) ++jdg;
	ans+=2*v2.size()-jdg;
	printf("%d\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}