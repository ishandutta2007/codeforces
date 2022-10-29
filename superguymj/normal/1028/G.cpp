#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const LL M=10004205361450474ll;
LL p[10005];
map <LL,LL> mp[10];

LL get(LL x,int k)
{
	if(mp[k].count(x)) return mp[k][x];
	LL y=min(10000ll,x);
	if(k==1) return mp[k][x]=x+y-1;
	if(y==10000)
	{
		LL ret=y;
		rep(i,2,k) ret=ret*(y+1)+y;
		return mp[k][x]=x+ret-1;
	}
	LL ret=x;
	rep(i,1,y+1) ret=get(ret,k-1)+2;
	return mp[k][x]=ret-2;
}

int query(int n)
{
	printf("%d",n);
	rep(i,1,n) printf(" %lld",p[i]);
	puts(""),fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}

void solve(LL l,LL r,int k)
{
	if(k==1)
	{
		int y=min(10000ll,l);
		rep(i,1,y) p[i]=l+i-1;
		query(y);
		return;
	}
	LL y=min(10000ll,l),lst=l;
	int tot=0;
	rep(i,1,y)
	{
		p[++tot]=get(lst,k-1)+1,lst=p[tot]+1;
		if(p[tot]>r) {--tot; break;}
	}
	int ret=query(tot);
	if(ret==-1) return;
	if(ret==0) {solve(l,p[1]-1,k-1); return;}
	if(ret==tot) {solve(p[tot]+1,r,k-1); return;}
	solve(p[ret]+1,p[ret+1]-1,k-1);
}

int main()
{
	solve(1,M,5);
	return 0;
}