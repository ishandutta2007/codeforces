#include<bits/stdc++.h>
#define pb push_back
#define ins(xx) pb(make_pair(xx/d,x))
const int N=200005;
using namespace std;
typedef pair<int,int> pi;
int n,m,d,t,tt,loc,q[N];
pi p[N];
long long now,tmp,ans,a,b;
vector<pi>vn[N],vm[N];
vector<int>en[N],em[N];
inline int gcd(int x,int y){
	for(;y;)swap(x,y),y%=x;
	return x;
}
void exgcd(int x,int y){
	if(y)exgcd(y,x%y),swap(a,b),b-=x/y*a;
}
inline int cal(int x,int y,int c){
	a=c,b=0,exgcd(x,y);
	return (a%y+y)%y;
}
inline void sol(vector<pi>v,vector<int>u,int n,int m){
	tt=u.size(),n/=d;
	for(int i=0;i<tt;i++)
	q[i]=cal(m/d,n,u[i]);
	t=v.size();
	for(int i=0;i<t;i++)
	p[i]=v[i],p[i].first=cal(m/d,n,v[i].first);
	sort(p,p+t),sort(q,q+tt);q[tt]=n;
	now=1e18;
	for(int i=0;i<t;i++){
		tmp=1ll*p[i].first*m;
		if(p[i].second<now+tmp)
		now=p[i].second-tmp;
		else p[i].second=now+tmp;
	}
	now+=1ll*n*m,loc=p[t-1].first-n;
	for(int i=0,j=0;i<t;i++){
		for(;q[j+1]<=p[i].first;j++);
		tmp=1ll*p[i].first*m;
		if(loc+1<p[i].first||
		loc+1==p[i].first&&q[j]!=loc+1)
		ans=max(ans,now+tmp-m);
		if(p[i].second<now+tmp)
		now=p[i].second-tmp;
		loc=p[i].first;
	}
}
int x,y;
int main(){
	scanf("%d%d",&n,&m);
	if((d=gcd(n,m))>=N)return puts("-1"),0;
	for(scanf("%d",&t);t--;)
	scanf("%d",&x),y=x%d,
	vn[y].ins(x),vm[y].ins(x%m),en[y].pb(x);
	for(scanf("%d",&t);t--;)
	scanf("%d",&x),y=x%d,
	vn[y].ins(x%n),vm[y].ins(x),em[y].pb(x);
	for(int i=0;i<d;i++)
	if(vn[i].size())
	sol(vn[i],en[i],n,m),
	sol(vm[i],em[i],m,n);
	else return puts("-1"),0;
	printf("%lld",ans);
}