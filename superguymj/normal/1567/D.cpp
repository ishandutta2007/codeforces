#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
typedef long long LL;
LL n,m,ans[10000],tot,k,hp[100000];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;	
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void push(int x)
{
	if(++k,x==1) {ans[++*ans]=1; return;}
	hp[++tot]=-x;
	push_heap(hp+1,hp+1+tot);
}

void pop()
{
	pop_heap(hp+1,hp+1+tot),--tot,--k;
}

void solve()
{
	n=getint(),m=getint();
	int p=1,x=n;
	tot=0,k=0,*ans=0;
	while(x)
	{
		if(k+(x%10)>=m)
		{
			rep(i,1,tot) ans[++*ans]=-hp[i];
			rep(i,1,m-k-1) ans[++*ans]=p;
			ans[++*ans]=n;
			rep(i,1,m-1) ans[m]-=ans[i];
			k=m;
			break;
		}
		rep(i,1,x%10) push(p);
		p*=10,x/=10;
	}
	while(k<m)
	{
		x=-hp[1]/10,pop();
		if(k+10>=m)
		{
			rep(i,1,tot) ans[++*ans]=-hp[i];
			rep(i,1,m-k-1) ans[++*ans]=x;
			ans[++*ans]=n;
			rep(i,1,m-1) ans[m]-=ans[i];
			break;
		}
		rep(i,1,10) push(x);
	}
	rep(i,1,m) printf("%lld ",ans[i]);
	puts("");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}