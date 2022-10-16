#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n[2];
string s[2];
void solve(int x,int id)
{
	if(x<2)
	{
		s[id]+=('0'+x);
		return ;
	}
	solve(x/2,id);
	s[id]+=('0'+x%2);
}
bool check()
{
//	/*
	int l=0,r=s[0].size()-1;
	while(l<=r&&s[0][l]=='1')
		l++;
	while(l<=r&&s[0][r]=='1')
		r--;
	string x=s[0].substr(l,r-l+1);
//	cout<<l<<" "<<r<<endl;
	int ll=0,rr=s[1].size()-1;
	while(ll<=rr&&s[1][ll]=='1')
		ll++;
	while(ll<=rr&&s[1][rr]=='1')
		rr--;
	if(l>ll)
		return 0;
	if((s[0].size()-r)>(s[1].size()-rr))
		return 0;
	string y=s[1].substr(ll,rr-ll+1);
//	cout<<x<<" "<<y<<endl;
//	cout<<endl;
	if(x==y)
		return 1;
//	*/
	/*
	for(int i=0;i+s[0].size()<=s[1].size();i++)
		if(s[1].substr(i,s[0].size())==s[0])
			return 1;
	*/
	return 0;
}
signed main()
{
	n[0]=read();
	n[1]=read();
	if(n[0]==n[1])
	{
		puts("YES");
		return 0;
	}
	if(n[1]%2==0)
	{
		puts("NO");
		return 0;
	}
	solve(n[0],0);
	solve(n[1],1);
	if(check())
	{
		puts("YES");
		return 0;
	}
	reverse(ALL(s[1]));
	if(check())
	{
		puts("YES");
		return 0;
	}
	while(n[0]%2==0)
		n[0]/=2;
	s[0]="";
	solve(n[0],0);
	if(check())
	{
		puts("YES");
		return 0;
	}
	reverse(ALL(s[1]));
	if(check())
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}