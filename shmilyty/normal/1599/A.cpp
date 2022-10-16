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
int n,x,y,c1,c2,cnt,a[200001];
string s;
vector<int> vl,vr;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(!i||s[i]!=s[i-1])
			cnt++;
	for(int i=n-cnt+1;i<=n;i++)
		vr.push_back(a[i]);
	for(int i=n-cnt;i;i--)
		vl.push_back(a[i]);
	for(int i=0;i<vl.size();i++)
		if(i&1)
		{
			if(s[0]=='R')
				vl[i]=-vl[i]; 
		}
		else
		{
			if(s[0]=='L')
				vl[i]=-vl[i];
		}
	for(int i=0;i<s.size();i++)
		if(i==0||s[i]!=s[i-1])
			cout<<vr[c1++]<<" "<<s[i]<<endl;
		else
		{
			if(vl[c2]<0)
				cout<<-vl[c2++]<<" R\n";
			else
				cout<<vl[c2++]<<" L\n";
		}
	return 0;
}