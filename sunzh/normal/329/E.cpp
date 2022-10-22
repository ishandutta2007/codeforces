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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
PII a[100010];
PII X[100010],Y[100010];
int t[100010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i].fi=read(),a[i].se=read(),X[i]=mp(a[i].fi,i),Y[i]=mp(a[i].se,i);
	sort(X+1,X+n+1,[&](PII x,PII y){
		return x.fi==y.fi?a[x.se].se<a[y.se].se:x.fi<y.fi;
	});
	sort(Y+1,Y+n+1,[&](PII x,PII y){
		return x.fi==y.fi?a[x.se].fi<a[y.se].fi:x.fi<y.fi;
	});
	long long bsta=0,bstb=0,nxa=0,nxb=0;
	bool f1=0,f2=0;
	for(int i=1;i<=(n>>1);++i){
		bsta+=2ll*X[n-i+1].fi-2ll*X[i].fi;
		bstb+=2ll*Y[n-i+1].fi-2ll*Y[i].fi;
		if(i!=(n>>1)){
			nxa+=2ll*X[n-i+1].fi-2ll*X[i].fi;
			nxb+=2ll*Y[n-i+1].fi-2ll*Y[i].fi;
		}
		// t[X[i].se]=i;t[X[n-i+1].se]=n-i+1;
	}
	if(n&1){
		nxa+=max(2ll*(X[(n+1>>1)].fi-X[(n+1>>1)-1].fi),2ll*(X[(n+1>>1)+1].fi-X[(n+1>>1)].fi));
		nxb+=max(2ll*(Y[(n+1>>1)].fi-Y[(n+1>>1)-1].fi),2ll*(Y[(n+1>>1)+1].fi-Y[(n+1>>1)].fi));
	}
	int px=X[n+1>>1].fi,py=Y[n+1>>1].fi;
	int cnt1=0,cnt2=0,cnt3=0;
	// printf("%lld %lld %lld %lld,%d %d\n",bsta,nxa,bstb,nxb,px,py);
	for(int i=1;i<=n;++i){
		if(a[i].fi>px&&a[i].se<=py) f1=1;
		if(a[i].fi>px&&a[i].se>py) f2=1;
		if(a[i].fi==px) ++cnt1;
		if(a[i].fi==px&&a[i].se==py) ++cnt2;
		if(a[i].se==py) ++cnt3;
		// if(t[Y[i].se]){
		// 	if(t[Y[i].se]<=(n>>1)) f1=1;else f2=1;
		// }
	}
	if((n%2==0||(cnt1==cnt2&&cnt2==cnt3))&&f1&&f2) printf("%lld\n",max(nxa+bstb,bsta+nxb));
	else printf("%lld\n",bsta+bstb);
}