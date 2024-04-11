#include<bits/stdc++.h>
const int N=200005;
const char mp[]={'L','D','U','R'};
using namespace std;
typedef long long ll;
int n,m,l,r,ans[N*10];
struct dat{
	ll t,x;
}s0[N],s1[N],tp;
inline void cal(ll a,ll d,ll b){
	b+=a;
	//cerr<<a<<"<="<<d<<"*s<="<<b<<endl;
	if(d==0){
		if(a>0||b<0)r=-1;
		return;
	}
	if(d<0)a=-a,b=-b,d=-d,swap(a,b);
	if(b<0){r=-1;return;}
	l=max((ll)l,(a+d-1)/d),r=min((ll)r,b/d);
	//cerr<<"::"<<l<<','<<r<<endl;
}
inline void sol(dat*a){
	sort(a,a+n,[](dat u,dat v){
		return u.t%m<v.t%m;
	});
	l=0,r=m;
	tp=a[n];
	for(int i=0;i<=n;i++){
		//cerr<<tp.t<<' '<<tp.x<<"?\n";
		cal(tp.x-a[i].x,tp.t/m-(i<n?a[i].t/m:-1),
		(i<n?a[i].t%m:m)-tp.t%m);
		tp=a[i];
	}
	if(l>r)puts("NO"),exit(0);
	tp=a[n];
	for(int i=0;i<=n;i++){
		if(i<n)a[i].x-=a[i].t/m*l,a[i].t%=m;
		else a[i].x=l;
		for(int j=tp.t+1;j<=tp.t+a[i].x-tp.x;j++)
		ans[j]++;
		tp=a[i];
	}
}
ll t,x,y;
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld%lld%lld",&t,&x,&y);
		if(abs(x)+abs(y)>t||(x+y+t&1))
		return puts("NO"),0;
		s0[i]={t,x+y+t>>1},s1[i]={t,x-y+t>>1};
	}
	sol(s0);
	for(int i=1;i<=m;i++)
	ans[i]<<=1;
	sol(s1);
	for(int i=1;i<=m;i++)
	putchar(mp[ans[i]]);
}