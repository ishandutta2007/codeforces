#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=410000;
int n;
struct atom{
	pii a,b;
}a[N];
int tmp[N],m;
int ma[N<<2],mi[N<<2];
void build(int me,int l,int r){
	ma[me]=-(1e9);
	mi[me]=1e9;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(me<<1,l,mid);
	build(me<<1|1,mid+1,r);
}
void add(int me,int l,int r,int x,int y,int dl,int dr){
	if(x<=l&&r<=y){
		ma[me]=max(ma[me],dl);
		mi[me]=min(mi[me],dr);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(me<<1,l,mid,x,y,dl,dr);
	if(y>mid)add(me<<1|1,mid+1,r,x,y,dl,dr);
}
bool gkd(int me,int l,int r,int si,int sa){
	sa=max(sa,ma[me]);
	si=min(si,mi[me]);
	if(sa>=1&&sa>si){
		//printf("%d %d\n",si,sa);
		return 1;
	}
	if(l==r)return 0;
	int mid=(l+r)>>1;
	return gkd(me<<1,l,mid,si,sa)|gkd(me<<1|1,mid+1,r,si,sa);
}
bool check(){
	build(1,1,m);
	rep(i,1,n){
		add(1,1,m,a[i].a.fi,a[i].a.se,a[i].b.fi,a[i].b.se);
	}
	return gkd(1,1,m,1e9,-1e9);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d%d%d",&a[i].a.fi,&a[i].a.se,&a[i].b.fi,&a[i].b.se);
		tmp[++m]=a[i].a.fi;
		tmp[++m]=a[i].a.se;
		tmp[++m]=a[i].b.fi;
		tmp[++m]=a[i].b.se;
	}
	sort(tmp+1,tmp+1+m);
	m=unique(tmp+1,tmp+1+m)-tmp-1;
	rep(i,1,n){
		a[i].a.fi=lower_bound(tmp+1,tmp+1+m,a[i].a.fi)-tmp;
		a[i].b.fi=lower_bound(tmp+1,tmp+1+m,a[i].b.fi)-tmp;
		a[i].a.se=lower_bound(tmp+1,tmp+1+m,a[i].a.se)-tmp;
		a[i].b.se=lower_bound(tmp+1,tmp+1+m,a[i].b.se)-tmp;
	}
	if(check()){
		puts("NO");
		return 0;
	}
	rep(i,1,n)swap(a[i].a,a[i].b);
	if(check()){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}