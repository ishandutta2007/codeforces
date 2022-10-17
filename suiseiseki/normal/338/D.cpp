#include <cstdio>
typedef long long LL;
const int N=1e4+5;
int k;
LL x,y,m[N],r[N];
LL mul(LL x,LL p,LL mod){
	if(p<0){
		x=-x;
		p=-p;
	}
	LL ret=0;
	for(;p;p>>=1,x=(x+x)%mod){
		if(p&1){
			ret=(ret+x)%mod;
		}
	}
	return ret;
}
LL exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
LL gcd(LL x,LL y){
	return y?gcd(y,x%y):x;
}
LL lcm(LL x,LL y){
	return x/gcd(x,y)*y;
}
LL China(int n){
	LL M=m[1],R=r[1];
	for(int i=2;i<=n;i++){
		LL a=M,b=m[i],c=r[i]-R,x,y,d=exgcd(a,b,x,y);
		if(c%d){
			return -1;
		}
		a/=d,b/=d,c/=d,x=(mul(x,c,b)+b)%b;
		R+=x*M,M*=m[i]/d,R=(R+M)%M;
	}
	R=(R+M-1)%M+1;
	if(R<1||R+k-1>y){
		return -1;
	}
	return R;
}
int main(){
	scanf("%lld%lld%d",&x,&y,&k);
	LL xx=1;
	for(int i=1;i<=k;i++){
		scanf("%lld",&m[i]);
		if((xx=lcm(xx,m[i]))>x){
			puts("NO");
			return 0;
		}
		r[i]=((m[i]-i+1)%m[i]+m[i])%m[i];
	}
	LL yy=China(k);
	if(yy==-1){
		puts("NO");
		return 0;
	}
	for(int i=1;i<=k;i++){
		if(gcd(xx,yy+i-1)!=m[i]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}