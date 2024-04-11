#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=110000;
int n,w;
int a[N],b[N];
struct fen{
	LL a,b;
	//a/b
	inline fen(LL _a=0,LL _b=0){
		a=_a;
		b=_b;
		if(b<0){
			a=-a;
			b=-b;
		}
	}
}x[N],y[N],k1[N],k2[N];
inline bool operator <(const fen &a,const fen &b){
	return a.a*b.b<a.b*b.a;
}
inline bool operator ==(const fen &a,const fen &b){
	return a.a*b.b==a.b*b.a;
}
inline fen operator +(const fen &a,const fen &b){
	return fen(a.a+b.a,a.b);
}
inline fen operator -(const fen &a,const fen &b){
	return fen(a.a-b.a,a.b);
}
inline fen operator *(const fen &a,const int &b){
	return fen(a.a*b,a.b);
}
int id[N];
fen tmp[N];int m;
int cnt[N];
inline bool cmp(const int &a,const int &b){return x[a]<x[b];}
void add(int x,int v){
	for(;x<=m;x+=(x&(-x)))cnt[x]+=v;
}
int ask(int x){
	int res=0;
	for(;x;x-=(x&(-x)))res+=cnt[x];
	return res;
}
LL lu1(){
	LL ans=0;
	rep(i,1,n)id[i]=i;
	sort(id+1,id+1+n,cmp);
	rep(i,1,n)tmp[i]=k1[i];
	sort(tmp+1,tmp+1+n);
	reverse(id+1,id+1+n);
	m=unique(tmp+1,tmp+1+n)-tmp-1;
	memset(cnt,0,sizeof cnt);
	rep(i,1,n){
		int j=i;
		while(j<n&&x[id[j+1]]==x[id[i]])++j;
		rep(k,i,j)ans+=ask(lower_bound(tmp+1,tmp+1+m,k1[id[k]])-tmp);
		rep(k,i,j)add(lower_bound(tmp+1,tmp+1+m,k1[id[k]])-tmp,1);
		i=j;
	}
	return ans;
}
LL lu2(){
	LL ans=0;
	rep(i,1,n)id[i]=i;
	sort(id+1,id+1+n,cmp);
	rep(i,1,n)tmp[i]=k2[i];
	sort(tmp+1,tmp+1+n);
	reverse(id+1,id+1+n);
	m=unique(tmp+1,tmp+1+n)-tmp-1;
	memset(cnt,0,sizeof cnt);
	rep(i,1,n){
		int j=i;
		while(j<n&&x[id[j+1]]==x[id[i]])++j;
		rep(k,i,j)ans+=ask(lower_bound(tmp+1,tmp+1+m,k2[id[k]])-tmp-1);
		rep(k,i,j)add(lower_bound(tmp+1,tmp+1+m,k2[id[k]])-tmp,1);
		i=j;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&w);
	rep(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
		x[i]=fen(1,a[i]);
		y[i]=fen(b[i],a[i]);
		k1[i]=y[i]-x[i]*w;
		k2[i]=y[i]+x[i]*w;
	}
	printf("%lld\n",lu1()-lu2());
	return 0;
}