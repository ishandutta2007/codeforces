#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int MAXN=2e5;
const int MAXT=1e4;
const int INF=2e9+5;
int n,m,K;
pii a[MAXN+5],b[MAXN+5],c[MAXN+5],d[MAXN+5];
int cnt_a,cnt_b,cnt_c,cnt_d,sum_a[MAXN+5],sum_b[MAXN+5],sum_c[MAXN+5],sum_d[MAXN+5];
int chosen[MAXN+5];
struct Book{
	int t;
	bool a,b;
}book[MAXN+5];

int pos_a,pos_b,pos_d;
pii check(int v,int i){
	int num=0;
	int sum=0;
	pos_a=max(0,K-i);pos_b=max(0,K-i);pos_d=0;
	
	int l=max(0,K-i),r=cnt_a;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(a[mid].fi<=v)l=mid;
		else r=mid-1;
	}
	pos_a=l;
	num+=(l-max(0,K-i));
	sum+=sum_a[l]-sum_a[K-i];
	
	l=max(0,K-i),r=cnt_b;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(b[mid].fi<=v)l=mid;
		else r=mid-1;
	}
	pos_b=l;
	num+=(l-max(0,K-i));
	sum+=sum_b[l]-sum_b[K-i];
	
	l=0,r=cnt_d;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(d[mid].fi<=v)l=mid;
		else r=mid-1;
	}
	pos_d=l;
	num+=l;
	sum+=sum_d[l];
	return mk(num,sum);
}

int main() {
	cin>>n>>m>>K;
	for(int i=1;i<=n;++i){
		cin>>book[i].t>>book[i].a>>book[i].b;
		if(book[i].a && book[i].b){
			c[++cnt_c]=mk(book[i].t,i);
		}
		else if(book[i].a){
			a[++cnt_a]=mk(book[i].t,i);
		}
		else if(book[i].b){
			b[++cnt_b]=mk(book[i].t,i);
		}
		else{
			d[++cnt_d]=mk(book[i].t,i);
		}
	}
	sort(a+1,a+cnt_a+1);
	sort(b+1,b+cnt_b+1);
	sort(c+1,c+cnt_c+1);
	sort(d+1,d+cnt_d+1);
	for(int i=1;i<=cnt_a;++i)sum_a[i]=sum_a[i-1]+a[i].fi;
	for(int i=1;i<=cnt_b;++i)sum_b[i]=sum_b[i-1]+b[i].fi;
	for(int i=1;i<=cnt_c;++i)sum_c[i]=sum_c[i-1]+c[i].fi;
	for(int i=1;i<=cnt_d;++i)sum_d[i]=sum_d[i-1]+d[i].fi;
	
	int ans=INF;
	int ansi=-1,ansv=0;
	for(int i=0;i<=K && i<=cnt_c;++i){
		if(K-i>cnt_a||K-i>cnt_b)continue;
		int curans=sum_c[i]+sum_a[K-i]+sum_b[K-i];
		int rest=m-i-(K-i)*2;
		if(rest<0)continue;
		if(rest==0){
			if(curans<ans){
				ans=curans;
				ansi=i;
				ansv=0;
			}
			continue;
		}
		int l=0,r=MAXT+1;
		while(l<r){
			int mid=(l+r)>>1;
			int num=check(mid,i).fi;
			if(num<rest)l=mid+1;
			else r=mid;
		}
		if(l>MAXT)continue;
		pii res=check(l,i);
		assert(res.fi>=rest);
		curans+=res.se-(res.fi-rest)*l;
		if(curans<ans){
			ans=curans;
			ansi=i;
			ansv=l;
		}
	}
	for(int i=K+1;i<=m && i<=cnt_c;++i){
		if(K-i>cnt_a||K-i>cnt_b)continue;
		int curans=sum_c[i];
		int rest=m-i;
		if(rest==0){
			if(curans<ans){
				ans=curans;
				ansi=i;
				ansv=0;
			}
			continue;
		}
		int l=0,r=MAXT+1;
		while(l<r){
			int mid=(l+r)>>1;
			int num=check(mid,i).fi;
			if(num<rest)l=mid+1;
			else r=mid;
		}
		if(l>MAXT)continue;
		pii res=check(l,i);
		assert(res.fi>=rest);
		curans+=res.se-(res.fi-rest)*l;
		if(curans<ans){
			ans=curans;
			ansi=i;
			ansv=l;
		}
	}
	if(ansi==-1){cout<<-1<<endl;return 0;}
	cout<<ans<<endl;
	if(ansi<=K){
		for(int j=1;j<=ansi;++j)cout<<c[j].se<<" ";
		for(int j=1;j<=K-ansi;++j)cout<<a[j].se<<" ";
		for(int j=1;j<=K-ansi;++j)cout<<b[j].se<<" ";
		int rest=m-ansi-(K-ansi)*2;
		assert(rest>=0);
		if(rest==0)return 0;
		pii res=check(ansv,ansi);
		int t=res.fi-rest;
		while(t && pos_a>K-ansi && a[pos_a].fi==ansv){--t;--pos_a;}
		while(t && pos_b>K-ansi && b[pos_b].fi==ansv){--t;--pos_b;}
		while(t && pos_a>0 && d[pos_d].fi==ansv){--t;--pos_d;}
		assert(t==0);
		for(int j=K-ansi+1;j<=pos_a;++j)cout<<a[j].se<<" ";
		for(int j=K-ansi+1;j<=pos_b;++j)cout<<b[j].se<<" ";
		for(int j=1;j<=pos_d;++j)cout<<d[j].se<<" ";
	}
	else{
		for(int j=1;j<=ansi;++j)cout<<c[j].se<<" ";
		int rest=m-ansi;
		if(rest==0)return 0;
		pii res=check(ansv,ansi);
		int t=res.fi-rest;
		while(t && pos_a>K-ansi && a[pos_a].fi==ansv){--t;--pos_a;}
		while(t && pos_b>K-ansi && b[pos_b].fi==ansv){--t;--pos_b;}
		while(t && pos_a>0 && d[pos_d].fi==ansv){--t;--pos_d;}
		assert(t==0);
		for(int j=1;j<=pos_a;++j)cout<<a[j].se<<" ";
		for(int j=1;j<=pos_b;++j)cout<<b[j].se<<" ";
		for(int j=1;j<=pos_d;++j)cout<<d[j].se<<" ";
	}
	return 0;
}