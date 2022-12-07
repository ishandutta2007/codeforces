#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define maxn 401010
int d1[maxn],d2[maxn],a[maxn],st[maxn],sum[maxn],D2[maxn],b[maxn],c[maxn],out[maxn];
pint s1[maxn],s2[maxn];
int main()
{
	int n,m,lis=0,inf=1145141919;
	scanf("%d %d",&n,&m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n+10) s1[i]=s2[i]=mp(-1,-1);
	
	rep(i,n+10) d1[i]=inf;d1[0]=0;
	rep(i,n){
		int t=lower_bound(d1,d1+n+5,a[i])-d1;
		if(a[i]<d1[t]) s1[i]=mp(t,a[i]),d1[t]=a[i];
	}
	rep(i,n+2){if(d1[i]<inf) lis=i;}
	memset(d2,0,sizeof(d2));d2[0]=-inf;
	for(int i=n-1;i>=0;i--){
		int t=lower_bound(d2,d2+n+5,-a[i])-d2;
		if(-a[i]<d2[t]) s2[i]=mp(t,d2[t]),d2[t]=-a[i];
	}
	rep(i,n+10) D2[i]=d2[i];
	
	memset(sum,0,sizeof(sum));
	memset(st,-1,sizeof(st));
	rep(i,n+10) d1[i]=inf;d1[0]=0;
	rep(i,n){
		if(s2[i].fi>=0) d2[s2[i].fi]=s2[i].se;
		//rep(j,n) cout<<d1[j]<<' ';cout<<endl;
		//rep(j,n) cout<<d2[j]<<' ';cout<<endl;
		int x=lower_bound(d1,d1+n+5,a[i])-d1,y=lower_bound(d2,d2+n+5,-a[i])-d2;
		//cout<<x<<' '<<y<<endl;
		if(x+y-1==lis) st[i]=x,sum[x]++;
		if(s1[i].fi>=0) d1[s1[i].fi]=s1[i].se;
	}
	//rep(i,n) cout<<st[i]<<' ';cout<<lis<<endl;
	
	vector<pint> p;
	rep(i,m){
		scanf("%d %d",&b[i],&c[i]);
		b[i]--;
		p.pb(mp(b[i],i));
	}
	sort(All(p));
	
	rep(i,n+10) d1[i]=inf;d1[0]=0;rep(i,n+10) d2[i]=D2[i];
	if(s2[0].fi>=0) d2[s2[0].fi]=s2[0].se;
	int now=0;
	rep(i,m){
		int s=p[i].fi,t=p[i].se;
		while(s>now){
			if(s1[now].fi>=0) d1[s1[now].fi]=s1[now].se;
			now++;
			if(s2[now].fi>=0) d2[s2[now].fi]=s2[now].se;
		}
		out[t]=lis-1;if(st[s]<0 || sum[st[s]]>1) out[t]=lis;
		//rep(j,n) cout<<d1[j]<<' ';cout<<endl;
		//rep(j,n) cout<<d2[j]<<' ';cout<<endl;
		int x=lower_bound(d1,d1+n+5,c[t])-d1,y=lower_bound(d2,d2+n+5,-c[t])-d2;
		out[t]=max(out[t],x+y-1);
	}
	
	rep(i,m) printf("%d\n",out[i]);
}