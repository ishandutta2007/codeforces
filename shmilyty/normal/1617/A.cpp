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
int t,n,num[26];
string s2;
void solve()
{
	char s1[101];
	scanf("%s",s1+1);
	n=strlen(s1+1);
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++)
		num[s1[i]-'a']++;
	sort(s1+1,s1+1+n);
	cin>>s2;
	if(s2!="abc"||!num[0]||!num[1]||!num[2])
	{
		for(int i=1;i<=n;i++)
			cout<<s1[i];
		cout<<endl;
		return ;
	}
	for(int i=1;i<=num[0];i++)
		cout<<'a';
	for(int i=1;i<=num[2];i++)
		cout<<'c';
	for(int i=1;i<=num[1];i++)
		cout<<'b';
	for(char i='d';i<='z';i++)
		for(int l=1;l<=num[i-'a'];l++)
			cout<<i;
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}