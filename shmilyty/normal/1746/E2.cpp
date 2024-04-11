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
std::vector<int> v1,v2,n1,n2;
int n,len1,len2;
string s;
signed main()
{
	n=len1=read();
	for(int i=1;i<=n;i++)
		v1.push_back(i);
	while(len1+len2>2)
	{
		int x=(len1+len2+1)/2-len2/2,y=len2/2;
		cout<<"? "<<(len1+len2+1)/2;
		for(int i=0;i<x;i++)
			cout<<" "<<v1[i];
		for(int i=0;i<y;i++)
			cout<<" "<<v2[i];
		cout<<endl;
		cin>>s;
		n1.clear();
		n2.clear();
		if(s[0]=='Y')
		{
			n1.insert(n1.end(),v1.begin(),v1.begin()+x);
			n1.insert(n1.end(),v2.begin(),v2.begin()+y);
			n2.insert(n2.end(),v1.begin()+x,v1.end());
		}
		else
		{
			n1.insert(n1.end(),v1.begin()+x,v1.end());
			n1.insert(n1.end(),v2.begin()+y,v2.end());
			n2.insert(n2.end(),v1.begin(),v1.begin()+x);
		}
		v1=n1;
		v2=n2;
		len1=v1.size();
		len2=v2.size();
	}
	v1.insert(v1.end(),ALL(v2));
	for(int i:v1)
	{
		cout<<"! "<<i<<endl;
		cin>>s;
		if(s[1]==')')
			return 0;
	}
	return 0;
}