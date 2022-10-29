#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1000005,mod=1000000007;
typedef long long LL;
char s[N];
int n,t[N],nxt[N][2],nxt0[N];
LL f[N],ans;

void inc(LL &x,LL y)
{
	if((x+=y)>=mod) x-=mod;
}

void ins(int x,int y)
{
	for(int i=x; i; i-=i&-i) t[i]=min(t[i],y);
}

int query(int x)
{
	int rt=n+1;
	for(int i=x; i<=n+1; i+=i&-i) rt=min(rt,t[i]);
	return rt;
}

void init()
{
	nxt[n+1][0]=nxt[n+1][1]=n+1;
	repd(i,n,1) if(s[i+1]=='0') nxt[i][0]=i+1,nxt[i][1]=nxt[i+1][1];
				else nxt[i][1]=i+1,nxt[i][0]=nxt[i+1][0];
	rep(i,1,n+1) t[i]=n+1;
	for(int i=n; i; --i)
	{
		if(s[i]=='1') continue;
		int j=i;
		while(j>1 && s[j-1]==s[j]) --j;
		int len=i-j+1,x=query(len+1);
		ins(len,j);
		if(x==n+1) nxt0[i]=n+1;
		else nxt0[i]=x+len;
		i=j;
	}
	if(s[1]=='0') inc(f[1],1);
	rep(i,1,n) if(s[i]=='1') {inc(f[i],1); break;}
}

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	init();
	bool jdg=0;
	rep(i,1,n-1) 
		if(s[i]=='0')
		{
			if(s[i+1]=='0') inc(f[i+1],f[i]);
			else if(jdg) inc(f[nxt0[i]],f[i]);
			inc(f[nxt[i][1]],f[i]);
		}
		else
		{
			jdg=1;
			inc(f[nxt[i][0]],f[i]);
			inc(f[nxt[i][1]],f[i]);
		}
	int x=1;
	repd(i,n,1) if(s[i]=='0') ++x; else break; 
	if(x==n+1) printf("%d\n",n);
	else
	{
		repd(i,n,1) if(s[i]=='1') inc(ans,f[i]);
		printf("%lld\n",ans*x%mod);
	}
	return 0;
}