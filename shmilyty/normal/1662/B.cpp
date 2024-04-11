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
int len,n[3][26],vis[26],num[3];
string s;
vector<array<int,2>> v;
vector<string> ans;
signed main()
{
	for(int i=0;i<3;i++)
	{
		cin>>s;
		for(char l:s)
			n[i][l-'A']++;
		num[i]=s.size();
	}
	len=min({num[0],num[1],num[2]});
	for(int i=0;i<26;i++)
	{
		while(v.size()<len&&(n[0][i]>0)+(n[1][i]>0)+(n[2][i]>0)>=2)
		{
			int j=0;
			for(int l=1;l<3;l++)
				if(n[l][i]<n[j][i])
					j=l;
			for(int l=0;l<3;l++)
				num[l]--;
			n[(j+1)%3][i]--;
			n[(j+2)%3][i]--;
			v.push_back({j,i});
		}
	}
	for(auto [i,l]:v)
	{
		s='A'+l;
		for(int j=0;j<26;j++)
			if(n[i][j]>0)
			{
				s+='A'+j;
				n[i][j]--;
				break;
			}
		ans.push_back(s);
	}
	while(num[0]||num[1]||num[2])
	{
		int x=min_element(num,num+3)-num;
		s="";
		for(int i=0;i<3;i++)
			if(x!=i&&num[i]>0)
			{
				num[i]--;
				for(int l=0;l<26;l++)
					if(n[i][l]>0)
					{
						n[i][l]--;
						s+='A'+l;
						break;
					}
			}
		if(s.size()==1)
			s+=s[0];
		ans.push_back(s);
	}
	cout<<ans.size()<<'\n';
	for(string i:ans)
		cout<<i<<'\n';
	return 0;
}