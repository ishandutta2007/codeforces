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
const int N=510000;
inline void read(int &x){
	x=0;char p=getchar();
	while(!(p<='9'&&p>='0'))p=getchar();
	while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}	
int gcd(int a,int b){
	if(!a||!b)return a+b;
	return gcd(b,a%b);
}
int cc[N<<2];
void build(int me,int l,int r){
	if(l==r){
		read(cc[me]);
		return;
	}
	int mid=(l+r)>>1;
	build(me<<1,l,mid);
	build(me<<1|1,mid+1,r);
	cc[me]=gcd(cc[me<<1|1],cc[me<<1]);
}
void modify(int me,int l,int r,int x,int y){
	if(l==r){
		cc[me]=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)modify(me<<1,l,mid,x,y);
	else modify(me<<1|1,mid+1,r,x,y);
	cc[me]=gcd(cc[me<<1|1],cc[me<<1]);
}
bool query(int me,int l,int r,int x,int y,int d,int &res){
	if(res<0)return 0;
	if(cc[me]%d==0)return 1;
	if(l==r){
		--res;
		if(res<0)return 0;
		else return 1;
	}
	int mid=(l+r)>>1;
	bool is=1;
	if(x<=mid)is=query(me<<1,l,mid,x,y,d,res);
	if(!is)return 0;
	if(y>mid)is=query(me<<1|1,mid+1,r,x,y,d,res);
	if(!is)return 0;
	return 1;
}
int n,Q;
int main(){
	scanf("%d",&n);
	build(1,1,n);
	scanf("%d",&Q);
	while(Q--){
		int ty;read(ty);
		if(ty==1){
			int l,r,x;read(l);read(r);read(x);
			int rp=1;
			if(query(1,1,n,l,r,x,rp)){
				if(rp<0)puts("NO");
				else puts("YES");
			}
			else puts("NO");
		}
		else{
			int x,y;read(x);read(y);
			modify(1,1,n,x,y);
		}
	}
	return 0;
}