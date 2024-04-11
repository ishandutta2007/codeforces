#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,k;
const double eps=1e-9;
PII a[100010];
int pl[100010],pr[100010];
double tl[100010],tr[100010],t[200010];
double dist(PII x,PII y){
	return sqrt(1ll*(x.fi-y.fi)*(x.fi-y.fi)+1ll*(x.se-y.se)*(x.se-y.se));
}
const double pi=acos(-1.0);
vector<PII>op[200010];
int tre[200010];
void upd(int x,int k){
	while(x<=n*2){
		tre[x]+=k;x+=x&-x;
	}
}
int qry(int x){
	int ret=0;
	while(x){
		ret+=tre[x];x-=x&-x;
	}
	return ret;
}
bool check(double md){
	memset(tre,0,sizeof(tre));
	int cnt=0;
	for(int i=1;i<=2*n;++i) vector<PII>().swap(op[i]);
	for(int i=1;i<=n;++i){
		double len=dist(mp(0,0),a[i]);
		if(md-len>-eps) continue ;
		double m=atan2(a[i].se,a[i].fi);
		double dt=acos(md/len);
		tl[i]=m-dt,tr[i]=m+dt;
		if(tl[i]<-pi) tl[i]+=2*pi;
		if(tr[i]>pi) tr[i]-=2*pi;
		if(tl[i]>tr[i]) swap(tl[i],tr[i]);
		t[i]=tl[i],t[i+n]=tr[i];
	}
	sort(t+1,t+n+n+1);
	for(int i=1;i<=n;++i){
		double len=dist(mp(0,0),a[i]);
		if(md-len>-eps) continue ;
		pl[i]=lower_bound(t+1,t+n+n+1,tl[i])-t;
		pr[i]=lower_bound(t+1,t+n+n+1,tr[i])-t;
		op[pl[i]].pb(mp(pr[i],1));
		op[pr[i]].pb(mp(pl[i],-1));
	}
	cnt=n*(n-1)>>1;
	for(int i=1;i<=2*n;++i){
		for(PII j:op[i]){
			if(j.se==1){
				cnt-=qry(j.fi)-qry(i-1);
				upd(j.fi,1);
			}
			else{
				upd(i,-1);
			}
		}
	}
	// printf("%lf,%d\n",md,cnt);
	return cnt>=k;
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i].fi=read(),a[i].se=read();
	double l=eps,r=2e4,res=2e4;
	while(r-l>eps){
		double mid=(l+r)/2;
		if(check(mid)) r=mid-eps,res=mid;else l=mid+eps;
	}
	printf("%.7lf\n",res);
}