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
int n,q;
int p[300010],w[300010];
vector<PII>vec[300010],vec2[300010];
long long ans[300010];
int stk[300010],top;
long long tre[300010];
void clear(){
	for(int i=1;i<=n;++i) tre[i]=9e18;
}
void update(int x,long long val){
	while(x<=n){
		tre[x]=min(tre[x],val);
		x+=x&-x;
	}
}
void upd(int x,int y){
	// printf("x:%d,y:%d\n",x,y);
	long long val=llabs(p[x]-p[y])*(w[x]+w[y]);
	update(y,val);
}
long long qry(int x){
	long long ret=9e18;
	while(x){
		ret=min(ret,tre[x]);
		x-=x&-x;
	}
	return ret;
}
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) p[i]=read(),w[i]=read();
	for(int i=1;i<=q;++i){
		int l=read(),r=read();
		vec[l].pb(mp(r,i));vec2[n-r+1].pb(mp(n-l+1,i));
		ans[i]=9e18;
	}
	clear();
	for(int i=n;i>=1;--i){
		while(top&&w[stk[top]]>=w[i]){
			upd(i,stk[top]);--top;
		}
		stk[++top]=i;
		for(PII j:vec[i]) ans[j.se]=min(ans[j.se],qry(j.fi));
	}
	reverse(w+1,w+n+1);reverse(p+1,p+n+1);
	top=0;
	clear();
	for(int i=n;i>=1;--i){
		while(top&&w[stk[top]]>=w[i]){
			upd(i,stk[top]);--top;
		}
		stk[++top]=i;
		for(PII j:vec2[i]) ans[j.se]=min(ans[j.se],qry(j.fi));
	}
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
}