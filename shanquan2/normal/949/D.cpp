#include<bits/stdc++.h>
using namespace std;

const int N=100000;
int n,d,b,z,a[N+5],s[N+5],r[N+5],sa[N+5],ra[N+5],sb[N+5],rb[N+5];
void init(){
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=n;i>=0;i--)r[i]=r[i+1]+a[i];
	z=n/(d+1);
	for(int i=0;i<=z;i++)sa[i]=s[i*(d+1)]-i*b;
	sb[z]=sa[z];
	for(int i=z-1;i>=0;i--)sb[i]=min(sa[i],sb[i+1]);
	for(int i=0;i<=z;i++)ra[i]=r[n-i*(d+1)+1]-i*b;
	rb[z]=ra[z];
	for(int i=z-1;i>=0;i--)rb[i]=min(ra[i],rb[i+1]);
}
bool calc(int l,int r){
	if(l<=0||r>n)return 0;
	if(l<=z){
		if(sb[l]<-b*(l-1))return 0;
	}
	r=n-r+1;
	if(r<=z){
		if(rb[r]<-b*(r-1))return 0;
	}
	return 1;
}
bool check(int x){
	return calc(x+1,n-x);
	int mid=n+1>>1;
	for(int i=0;i<=x&&i<mid;i++)
		if(calc(mid-i,mid-i+x))return 1;
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&d,&b);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	init();
	int h=0,t=n;
	while(h<t){
		int mid=h+t>>1;
		if(check(mid))t=mid;else h=mid+1;
	}
	printf("%d\n",h);
	return 0;
}