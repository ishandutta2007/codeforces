#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=300005,mod=998244353;
typedef long long LL;
int n,m,k,d1[N],d2[N],a[N],s[N],tot,num[N],nxt[N];
LL f[N];
map <pair<int,int>,bool> mp;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void dfs(int x,int l)
{
	if(d1[x]>1 || d2[x]>1) return;
	if(!d2[x])
	{
		if(!num[l]) s[++tot]=l;
		++num[l];
		return;
	}
	dfs(nxt[x],l+1);
}

int main()
{
	n=getint(),m=getint(),k=getint();
	rep(i,1,n)
	{
		int x=getint();
		rep(j,1,x) a[j]=getint();
		rep(j,1,x-1) if(!mp[make_pair(a[j],a[j+1])])
		{
			mp[make_pair(a[j],a[j+1])]=1;
			nxt[a[j]]=a[j+1],++d1[a[j+1]],++d2[a[j]];
		}
	}
	rep(i,1,k) if(!d1[i]) dfs(i,1);
	f[0]=1;
	rep(i,1,m) rep(j,1,tot) if(i-s[j]>=0)
		f[i]=(f[i]+f[i-s[j]]*num[s[j]])%mod;
	printf("%lld\n",f[m]);
	return 0;
}