#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
using namespace std;
typedef long long ll;
const ll P=75161927681ll,g=3,MAXN=524288;
ll mul(long long x,long long y){  
	ll tmp=(x*y-(ll)((long double)x/P*y+1.0e-8)*P);  
	return tmp<0 ? tmp+P : tmp;  
}  
ll pw(ll a,ll b){
	ll ret=1;
	for(;b;b>>=1,a=mul(a,a))
		if(b&1)ret=mul(ret,a);
	return ret;
}
void fft(ll *a,ll n,bool inv=0){
	ll w=1,d=pw(g,(P-1)/n),t;
	ll i,j,c,s;
	if(inv){
		for(i=1,j=n-1;i<j;swap(a[i++],a[j--]));
		for(t=pw(n,P-2),i=0;i<n;++i)a[i]=mul(a[i],t);
	}
	for(s=n>>1;s;s>>=w=1,d=mul(d,d))
		for(c=0;c<s;++c,w=mul(w,d))
			for(i=c;i<n;i+=s<<1)
				a[i|s]=mul((a[i]+P-(t=a[i|s]))%P,w),a[i]=(a[i]+t)%P;
	for(i=1;i<n;++i){
		for(j=0,s=i,c=n>>1;c;c>>=1,s>>=1)j=j<<1|s&1;
		if(i<j)swap(a[i],a[j]);
	}
}
ll a[MAXN],b[MAXN],c[MAXN],n,x,N;
int main(){
	//freopen("E.in","r",stdin);
	//freopen("E.out","w",stdout);
	scanf("%lld%lld",&n,&x);
	rep(i,n)scanf("%lld",a+i),a[i]=(a[i]<x);
	rep(i,n)a[i]+=a[i-1];
	for(ll i=0;i<=n;++i)++b[a[i]];
	for(ll i=0;i<=n;++i)c[i]=b[n-i];
	for(N=1;N<(n+1)*2;N<<=1);
	fft(b,N,0);fft(c,N,0);
	for(ll i=0;i<N;++i)b[i]=mul(b[i],c[i]);
	fft(b,N,1);
	for(ll i=n;i<=n*2;++i){
		if(i==n)b[i]=mul((P+b[i]-n-1)%P,pw(2,P-2));
		printf("%lld%c",b[i]," \n"[i==2*n]);
	}
	//system("pause");
	return 0;
}
/*
1 1 4 0 0 0 
0 0 0 4 1 1

*/