#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
/*
011...
0.2...
0.2...
0.2...
552554
..2..4
..2333
*/
int n,m,len[6];
string s[6];
char mp[61][61];
vector<string> ans,v;
signed main()
{
	for(int i=0;i<6;i++)
		cin>>s[i];
	sort(s,s+6);
	do{
		for(int i=0;i<6;i++)
			len[i]=s[i].size();
		if(len[0]+len[4]!=len[2]+1)
			continue;
		if(len[1]+len[3]!=len[5]+1)
			continue;
		if(s[0][0]!=s[1][0])
			continue;
		if(s[1].back()!=s[2][0])
			continue;
		if(s[2].back()!=s[3][0])
			continue;
		if(s[3].back()!=s[4].back())
			continue;
		if(s[4][0]!=s[5].back())
			continue;
		if(s[5][0]!=s[0].back())
			continue;
		if(s[2][len[0]-1]!=s[5][len[1]-1])
			continue;
		n=len[2];
		m=len[5];
		v.clear();
		v.resize(n);
		for(int i=0;i<n;i++)
			for(int l=0;l<m;l++)
				v[i]+=".";
		for(int i=0;i<len[0];i++)
			v[i][0]=s[0][i];
		for(int i=1;i<len[1];i++)
			v[0][i]=s[1][i];
		for(int i=1;i<len[2];i++)
			v[i][len[1]-1]=s[2][i];
		for(int i=1;i<len[3];i++)
			v[n-1][i+len[1]-1]=s[3][i];
		for(int i=0;i<len[4]-1;i++)
			v[i+len[0]-1][m-1]=s[4][i];
		for(int i=0;i<len[5]-1;i++)
			v[len[0]-1][i]=s[5][i];
		if(ans.empty())
			ans=v;
		ans=min(ans,v);
	}while(next_permutation(s,s+6));
	if(ans.empty())
		puts("Impossible");
	else
		for(string i:ans)
			cout<<i<<'\n';
	return 0;
}