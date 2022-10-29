#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
typedef long long LL;
char s[100];
int n;
LL p[100],f[20][20][2][2];
LL l,r;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int get(char c)
{
	if(isdigit(c)) return c-48;
	return c-'a'+10;
}

LL get()
{
	LL ret=0;
	rep(i,1,n) ret=ret*16+get(s[i]);
	return ret;
}

void inc(LL &x,LL y)
{
	x+=y;
}

//f[i][max][current 0/1][0/1]

bool check(int i,int mx,int c)
{
	if(i*4<=mx && mx<(i+1)*4)
	{
		mx-=i*4;
		if(!(c&(1<<mx))) return 0;
	}
	return 1;
}

LL query(LL n)
{
	if(n<0) return 0;
	rep(i,1,15) p[i]=n&15,n>>=4;
	memset(f,0,sizeof(f));
	rep(i,0,15) f[0][i][0][0]=1;
	rep(i,0,14) rep(j,0,15) rep(k,0,1) rep(t,0,1) if(f[i][j][k][t])
	{
		LL tmp=f[i][j][k][t],c=p[i+1];
		rep(x,0,j)
		{
			int _t=x<c?0:(x==c?t:1);
			int _k=k|(j==x);
			if(check(i,j,x))
				inc(f[i+1][j][_k][_t],tmp);
		}
	}
	LL ret=0;
	rep(i,0,15) inc(ret,f[15][i][1][0]);
	return ret;
}

void solve()
{
	scanf("%s",s+1),n=strlen(s+1);
	l=get()-1;
	scanf("%s",s+1),n=strlen(s+1);
	r=get();
	printf("%lld\n",query(r)-query(l));
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}