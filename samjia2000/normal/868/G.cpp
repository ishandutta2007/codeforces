#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int mo = 1e9+7;

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}
LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
		if (tim&1)ret=ret*x%mo;
	return ret;
}
LL n,k,p;
struct func{
	LL k,b;//kx+b
	func(const LL k_=0,const LL b_=0){k=k_;b=b_;}
	friend func operator + (func a,func b){return func(add(a.k,b.k),add(a.b,b.b));}
	friend func operator - (func a,func b){return func(dec(a.k,b.k),dec(a.b,b.b));}
	friend func operator * (func a,func b){return func(a.k*b.k%mo,(a.k*b.b+a.b)%mo);}
	func inv(){
		//kx+b
		LL ny=quickmi(k,mo-2);
		return func(ny,dec(0,b*ny%mo));
	}
	LL calc(LL x){return (k*x+b)%mo;}
};
func operator ^(func a,LL T){
	func ret=func(1,0);
	for(;T;T/=2,a=a*a)if (T&1)ret=ret*a;
	return ret;
}

LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}

pair<func,LL> calc(func f,LL x,LL tim){
	//0..tim-1
	if (tim==1)return make_pair(f,x);
	pair<func,LL> u=calc(f,x,tim/2);
	func fk=u.first;
	LL ret=u.second;
	ret=((fk.k+1)*ret+fk.b*(tim/2))%mo;
	fk=fk*fk;
	if (tim&1){
		ret=add(ret,fk.calc(x));
		fk=fk*f;
	}
	return make_pair(fk,ret);
}

void solve(LL n,LL k,func A,func B,LL &sum1,LL &sum2){
	if (n==1){
		sum1=A.b*quickmi(mo+1-A.k,mo-2)%mo;
		sum2=0;
		return;
	}
	func a=A.inv(),b=B.inv();
	a=a^(n/k);
	solve(k,n%k,A*(a*b),a*b,sum1,sum2);
	LL tmp=sum2;
	sum2=sum1;
	LL v1=(func(A.k,A.b*(n%k)%mo)^(n/k)).calc(tmp);
	LL v2=calc(func(A.k,A.b*k%mo),sum1,n/k).second;
	sum1=add(v1,v2);
}

int main(){
	int _;
	cin>>_;
	for(;_;_--){
		cin>>n>>k;
		p=(mo+1)/2;
		if (n==k){
			printf("%I64d\n",quickmi(p,mo-2));
			continue;
		}
		if (p==1){
			LL t=n/k;
			//t*k+n%k
			LL ret=(t*(t+1)/2%mo*k%mo+n%k*(t+1)%mo)%mo*quickmi(n,mo-2)%mo;
			printf("%I64d\n",ret);
			continue;
		}
		LL g=gcd(n,k);
		n/=g,k/=g;
		LL sum1,sum2;
		solve(n,k,func(1,1),func(mo+1-p,1),sum1,sum2);
		sum1=sum1*quickmi(n,mo-2)%mo;
		printf("%I64d\n",sum1);
	}
	return 0;
}