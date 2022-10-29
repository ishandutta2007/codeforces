#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1005,M=25,K=5005;
char s[N];
int n,x,p[M],f[N][K],t[K][10],fail[K];
int head,tail,q[K],cnt,ans;
bool c[K];

bool check(int len)
{
	int tmp=0;
	repd(i,len,1)
	{
		tmp+=p[i];
		if(tmp!=x && x%tmp==0) return 0;
	}
	return 1;
}

void build(int len)
{
	int x=1;
	rep(i,1,len) if(t[x][p[i]]) x=t[x][p[i]]; else t[x][p[i]]=++cnt,x=cnt;
	c[x]=1;
}

void acam()
{
    rep(i,1,9) t[0][i]=1;
    q[head=tail=0]=1;
    while(head<=tail)
    {
        int x=q[head++];
        rep(i,1,9)
            if(t[x][i])
            {
                int k=fail[x];
                fail[t[x][i]]=t[k][i];
				q[++tail]=t[x][i];
            }
			else t[x][i]=t[fail[x]][i];
        c[x]|=c[fail[x]];
    }
}

void dfs(int len,int tot)
{
	if(tot==x)
	{
		build(len);
		return;
	}
	rep(i,1,min(9,x-tot))
	{
		p[len+1]=i;
		if(check(len+1)) dfs(len+1,tot+i);
	}
}

void init()
{
	cnt=1,dfs(0,0);
	acam();
}

void chkmax(int &x,int y) {x=max(x,y);}

void dp()
{
	rep(i,0,n) rep(j,1,cnt) f[i][j]=-n;
	f[0][1]=0;
	rep(i,0,n-1) rep(j,1,cnt) if(!c[j] && f[i][j]>=0)
	{
		chkmax(f[i+1][j],f[i][j]);
		chkmax(f[i+1][t[j][s[i+1]-'0']],f[i][j]+1);
	}
	rep(i,1,cnt) if(!c[i]) chkmax(ans,f[n][i]);
	printf("%d\n",n-ans);
}

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	scanf("%d",&x);
	init();
	dp();
	return 0;
}