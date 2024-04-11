#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int n,m,k,vis;
map<string,vector<vector<string> > > fc;
map<string,string> va;
vector<string> v;
string s,fn;
int findpos(char c)
{
	for(int i=0;i<s.size();i++)
		if(s[i]==c)
			return i;
	return -1;
}
string del(string s)
{
	string ans="";
	for(int i=0;i<s.size();i++)
		if(s[i]!=' ')
			ans+=s[i];
	return ans;
}
void solve()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		if(s[i]=='('||s[i]==')'||s[i]==',')
			s[i]=' ';
	fn="";
	v.clear();
	istringstream ss(s);
	while(ss>>s)
		if(fn=="")
			fn=s;
		else
			v.push_back(s);
}
signed main()
{
	n=read();
	while(n--)
	{
		cin>>fn;
		solve();
		fc[fn].push_back(v);	
	}
	m=read();
	while(m--)
	{
		string s1,s2;
		cin>>s1>>s2;
		va[s2]=s1;
	}
	k=read();
	while(k--)
	{
		solve();
		int ans=0;
		for(int i=0;i<fc[fn].size();i++)
			if(fc[fn][i].size()==v.size())
			{
				int ok=1;
				for(int l=0;l<v.size();l++)
				{
					string f1=fc[fn][i][l],f2=va[v[l]];
					if(f1!=f2&&f1!="T")
					{
						ok=0;
						break;
					}
				}
				ans+=ok;
			}
		cout<<ans<<endl;
	}
	return 0;
}