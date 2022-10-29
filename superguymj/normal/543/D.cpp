#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int N=200005,mod=1000000007;
int n,x;
typedef long long LL;
LL f[N],g[N],s1[N],s2[N];
vector <int> s[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void dp_1(int x)
{
	f[x]=1;
	rep(i,0,int(s[x].size())-1)
		dp_1(s[x][i]),f[x]=f[x]*(f[s[x][i]]+1)%mod;
}

void dp_2(int x)
{
	s1[0]=s2[s[x].size()]=1;
	rep(i,0,int(s[x].size())-1)
		s1[i+1]=s1[i]*(f[s[x][i]]+1)%mod;
	repd(i,int(s[x].size())-1,0)
		s2[i]=s2[i+1]*(f[s[x][i]]+1)%mod;
	rep(i,0,int(s[x].size())-1)
		g[s[x][i]]=(g[x]*s1[i]%mod*s2[i+1]+1)%mod;
	rep(i,0,int(s[x].size())-1)
		dp_2(s[x][i]);
}

int main()
{
	n=getint();
	rep(i,2,n) s[x=getint()].pb(i);
	dp_1(1);
	g[1]=1,dp_2(1);
	rep(i,1,n) printf("%I64d ",f[i]*g[i]%mod);
	return 0;
}