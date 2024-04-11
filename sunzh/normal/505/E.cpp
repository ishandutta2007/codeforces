#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define int long long
#define PIP pair<int,pair<int,int> >
#define fi first
#define se second
#define mp make_pair 
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,m,k,p;
int h[100010],a[100010];
bool check(int x){
//	printf("x:%lld\n",x);
	priority_queue<PIP ,vector<PIP>, greater<PIP> >Q;
	for(int i=1;i<=n;++i){
		if(x-a[i]*m<h[i]) Q.push(mp(x/a[i],mp(i,x)));
//		else printf("i:%d\n",i);
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=k;++j){
			if(Q.empty()) return 1;
			PIP u=Q.top();Q.pop();
			if(u.fi<i) return 0;
			u.se.se+=p;u.fi=u.se.se/a[u.se.fi];
			if(u.se.se-a[u.se.fi]*m<h[u.se.fi]) Q.push(u);
		}
	}
	return Q.empty();
}
signed main(){
	n=read(),m=read(),k=read(),p=read();
	int maxa=0;
	for(int i=1;i<=n;++i) h[i]=read(),a[i]=read(),maxa=max(maxa,a[i]);
	int l=maxa,r=1e18,ans=1e18;
	while(l<=r){
//		printf("l:%lld,r:%lld\n",l,r);
		int mid=l+r>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	print(ans);
	return 0;
}