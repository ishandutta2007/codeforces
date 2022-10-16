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
int n,m;
array<int,2> pos[2];
vector<array<int,2>> v;
string a[18][18],mp0[]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"},mp1[]={"C","D","H","S"};
map<string,bool> vis;
bool check1(int x,int y)
{
	for(int i=x;i<=x+2;i++)
		for(int l=y;l<=y+2;l++)
			for(int ii=x;ii<=x+2;ii++)
				for(int ll=y;ll<=y+2;ll++)
					if(a[i][l][0]==a[ii][ll][0]&&(i!=ii||l!=ll))
						return 0;
	return 1;
}
bool check2(int x,int y)
{
	for(int i=x;i<=x+2;i++)
		for(int l=y;l<=y+2;l++)
			if(a[i][l][1]!=a[x][y][1])
				return 0;
	return 1;
}
void dfs(int x)
{
	if(x==2)
	{
		v.clear();
		for(int i=1;i+2<=n;i++)
			for(int l=1;l+2<=m;l++)
				if(check1(i,l)||check2(i,l))
					v.push_back({i,l});
		for(int i=0;i<v.size();i++)
			for(int l=i+1;l<v.size();l++)
				if(v[i][0]+2<v[l][0]||min(v[i][1],v[l][1])+2<max(v[i][1],v[l][1]))
				{
					puts("Solution exists.");
					if((!pos[0][0])&&(!pos[1][0]))
						puts("There are no jokers.");
					elif(pos[0][0]&&pos[1][0])
						cout<<"Replace J1 with "<<a[pos[0][0]][pos[0][1]]<<" and J2 with "<<a[pos[1][0]][pos[1][1]]<<".\n";
					elif(pos[0][0])
						cout<<"Replace J1 with "<<a[pos[0][0]][pos[0][1]]<<".\n";
					else
						cout<<"Replace J2 with "<<a[pos[1][0]][pos[1][1]]<<".\n";
					printf("Put the first square to (%lld, %lld).\n",v[i][0],v[i][1]);
					printf("Put the second square to (%lld, %lld).\n",v[l][0],v[l][1]);
					exit(0);
		}
		return ;
	}
	if(!pos[x][0])
	{
		dfs(x+1);
		return ;
	}
	for(int i=0;i<13;i++)
		for(int l=0;l<4;l++)
		if(!vis[mp0[i]+mp1[l]])
		{
			a[pos[x][0]][pos[x][1]]=mp0[i]+mp1[l];
			vis[mp0[i]+mp1[l]]=1;
			dfs(x+1);
			vis[mp0[i]+mp1[l]]=0;
		}
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
		{
			string s;
			cin>>s;
			if(s[0]=='J'&&s[1]<='2')
			{
				pos[s[1]-'1']={i,l};
				continue;
			}
			a[i][l]=s;
			vis[s]=1;
		}
	dfs(0);
	puts("No solution.");
	return 0;
}