#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=1005,INF=2000000000;
bool pa[N],pb[N];
int n;
LL a[N],b[N],ans[N];

struct D
{	
	LL val,id;
	
	bool operator < (const D &t) const
	{
		return val==t.val?id<t.id:val<t.val;
	}
} ;
set <D> s,t;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool check(LL k)
{
	rep(i,1,n) pa[i]=pb[i]=0;
	s.clear(),t.clear();
	rep(i,1,n) s.insert((D){a[i],i});
	rep(i,1,n) t.insert((D){b[i],i});
	rep(i,1,n)
	{
		D x=*s.rbegin();
		D y=*t.rbegin();
		if(x.val>y.val)
		{
			D z=(D){abs(x.val-k),0};
			if(t.upper_bound(z)==t.end()) return 0;
			D h=*t.upper_bound(z);
			if(h.val!=abs(x.val-k)) return 0;
			t.erase(h);
			pa[x.id]=1;
			if(x.val-k>=0) pb[h.id]=1;
			s.erase(x);
		}
		else
		{
			swap(x,y);
			D z=(D){abs(x.val-k),0};
			if(s.upper_bound(z)==s.end()) return 0;
			D h=*s.upper_bound(z);
			if(h.val!=abs(x.val-k)) return 0;
			s.erase(h);
			if(x.val-k<0) pa[h.id]=1;
			t.erase(x);
		}
	}
	puts("YES");
	rep(i,1,n)
	{
		if(pa[i]) a[i]=-a[i];
		if(pb[i]) b[i]=-b[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	rep(i,1,n) ans[i]=a[i]-a[n]+INF;
	ans[0]=-a[n]+INF,ans[n+1]=-b[n]+INF;
	LL pt=min(ans[0],ans[n+1]);
	rep(i,1,n) pt=min(pt,ans[i]);
	rep(i,1,n) printf("%lld ",ans[i]-pt);
	puts("");
	printf("%lld %lld\n",ans[0]-pt,ans[n+1]-pt);
	return 1;
}

void solve()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) b[i]=getint();
	rep(i,1,n)
	{
		LL x=abs(a[i]-b[1]);
		if(check(x)) return;
		x=abs(a[i]-b[1])+2*min(a[i],b[1]);
		if(check(x)) return;
	}
	puts("NO");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}