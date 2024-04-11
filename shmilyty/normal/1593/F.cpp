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
int t,n,a,b,X[45],f[45],t1[45],t2[45];
string s;
vector<int> v[2][45][45][45];
void dfs(int x,int s,int t,int aa,int bb,int cc)
{
	if(s>t)
	{
		if(!v[x][aa][bb][cc].empty())
			return ;
		if(t==n)
			for(int i=n/2+1;i<=n;i++)
				v[x][aa][bb][cc].push_back(f[i]);
		else
			for(int i=1;i<=n/2;i++)
				v[x][aa][bb][cc].push_back(f[i]);
		return ;
	}
	f[s]=1;
	dfs(x,s+1,t,(aa*10+X[s])%a,bb,cc+1);
	f[s]=2;
	dfs(x,s+1,t,aa,(bb*10+X[s])%b,cc);
	f[s]=0;
}
void solve()
{
	n=read();
	a=read();
	b=read();
	t1[0]=t2[0]=1;
	for(int i=1;i<=44;i++)
		t1[i]=t1[i-1]*10%a;
	for(int i=1;i<=44;i++)
		t2[i]=t2[i-1]*10%b;
	for(int i=0;i<2;i++)
		for(int l=0;l<a;l++)
			for(int j=0;j<b;j++)
				for(int k=0;k<n;k++)
					v[i][l][j][k].clear();
	cin>>s;
	for(int i=1;i<=n;i++)
		X[i]=s[i-1]-'0';
//	for(int i=1;i<=n;i++)
//		cout<<X[i]<<" ";
//	cout<<endl; 
	dfs(0,1,n/2,0,0,0);
	dfs(1,n/2+1,n,0,0,0);
//	puts("ok");
	int ans=INF,L=n/2,lst=n-(n/2);
//	cout<<a<<" "<<b<<" "<<L<<" "<<lst<<endl;
	for(int i=0;i<a;i++)
		for(int l=0;l<b;l++)
			for(int j=0;j<=L;j++)
				if(!v[0][i][l][j].empty())
					for(int k=0;k<=lst;k++)
					{
						if(j+k==0||j+k==n)
							continue;
						int aa=t1[k]*i%a,bb=t2[lst-k]*l%b;
//						cout<<i<<" "<<l<<" "<<j<<" "<<aa<<" "<<bb<<endl;
						int da=(a-aa)%a,db=(b-bb)%b;
						if(v[1][da][db][k].empty())
							continue;
						ans=min(ans,abs((n-j-k)-j-k));
					}
//	cout<<ans<<endl;
	for(int i=0;i<a;i++)
		for(int l=0;l<b;l++)
			for(int j=0;j<=L;j++)
				if(!v[0][i][l][j].empty())
					for(int k=0;k<=lst;k++)
					{
						if(j+k==0||j+k==n)
							continue;
						int aa=t1[k]*i%a,bb=t2[lst-k]*l%b;
						int da=(a-aa)%a,db=(b-bb)%b;
						if(v[1][da][db][k].empty())
							continue;
						if(abs((n-j-k)-j-k)==ans)
						{
							for(int q:v[0][i][l][j])
								cout<<((q==1)?'R':'B');
							for(int q:v[1][da][db][k])
								cout<<((q==1)?'R':'B');
							cout<<endl;
							return ; 
						}
					}
	puts("-1");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}