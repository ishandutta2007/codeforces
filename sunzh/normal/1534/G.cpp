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
priority_queue<int>L;
priority_queue<int,vector<int>,greater<int> >R;
PII a[800010];
int len=0;
int toL(int x){
	return x+len;
}
int toR(int x){
	return x-len;
}
int frL(int x){
	return x-len;
}
int frR(int x){
	return x+len;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i].fi=read(),a[i].se=read();
	for(int i=1;i<=n;++i){
		int x=a[i].fi,y=a[i].se;
		a[i].fi=x+y,a[i].se=x-y;
	}
	sort(a+1,a+n+1);
	L.push(toL(a[1].se));
	R.push(toR(a[1].se));
	// printf("%d %d\n",a[1].fi,a[1].se);
	long long ans=0;
	for(int i=2;i<=n;++i){
		len+=a[i].fi-a[i-1].fi;
		// printf("%d %d\n",a[i].fi,a[i].se);
		int l=frL(L.top()),r=frR(R.top());
		int x=a[i].se;
		// printf("l:%d,r:%d,%d\n",l,r,a[i].se);
		if(x<l){
			R.push(toR(l));
			L.pop();L.push(toL(x));L.push(toL(x));
			ans+=l-x;
		}
		else if(x>r){
			L.push(toL(r));R.pop();R.push(toR(x));R.push(toR(x));ans+=x-r;
		}
		else {
			L.push(toL(x)),R.push(toR(x));
		}
		// printf("%d\n",ans);
	}
	printf("%lld\n",ans>>1);
}