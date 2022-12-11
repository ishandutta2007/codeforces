#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int N = 205;
const int mo = 1e9+7;

int k;
LL l,r;
LL js[N],inv[N];
LL c[N];
struct comp{
	LL x,y;
	comp(const LL x_=0,const LL y_=0){x=x_;y=y_;}
}a0,a1;
LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}
comp operator +(comp a,comp b){return comp(add(a.x,b.x),add(a.y,b.y));}
comp operator -(comp a,comp b){return comp(dec(a.x,b.x),dec(a.y,b.y));}
comp operator *(comp a,comp b){return comp((a.x*b.x%mo+a.y*b.y%mo*5)%mo,(a.x*b.y%mo+a.y*b.x%mo)%mo);}
LL quickmi(LL x,LL tim){LL ret=1;for(;tim;tim/=2,x=x*x%mo)if (tim&1)ret=ret*x%mo;return ret;}
comp quickmi(comp x,LL tim){comp ret=comp(1,0);for(;tim;tim/=2,x=x*x)if (tim&1)ret=ret*x;return ret;}
comp getinv(comp a){
	LL tmp=(a.x*a.x%mo+mo-a.y*a.y%mo*5%mo)%mo;
	tmp=quickmi(tmp,mo-2);
	return comp(a.x*tmp%mo,dec(0,a.y*tmp%mo));
}

LL calc(int n,int m){return js[n]*inv[m]%mo*inv[n-m]%mo;}

LL solve(LL n){
	comp ret=comp(0,0);
	comp inv5=comp(0,quickmi(5,mo-2));
	fo(i,0,k)
	if (c[i]){
		comp sum=comp(0,0);
		fo(j,0,i){
			int tim=i-j*2;
			LL cv=calc(i,j);
			if (tim>0){
				comp u=quickmi(comp(mo-1,0),j)*quickmi(a0,tim);
				comp v=quickmi(u,n+1)-comp(1,0);
				u=u-comp(1,0);
				sum=sum+v*getinv(u)*comp(cv,0)*quickmi(comp(mo-1,0),j);
			}
			if (tim==0){
				if (j&1)sum=sum+comp(n&1?0:mo-1,0)*comp(cv,0);
				else sum=sum+comp((n+1)%mo,0)*comp(cv,0);
			}
			if (tim<0){
				comp u=quickmi(comp(mo-1,0),j)*quickmi(a1,-tim);
				comp v=quickmi(u,n+1)-comp(1,0);
				u=u-comp(1,0);
				sum=sum+v*getinv(u)*comp(cv,0)*quickmi(comp(mo-1,0),j);
			}
		}
		sum=sum*quickmi(inv5,i)*comp(c[i],0);
		ret=ret+sum;
	}
	return ret.x;
}

int main(){
	scanf("%d%I64d%I64d",&k,&l,&r);
	a0=comp((mo+1)/2,(mo+1)/2);
	a1=getinv(a0);
	js[0]=1;
	fo(i,1,k)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,k)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,k)inv[i]=inv[i]*inv[i-1]%mo;
	c[0]=1;
	fo(i,0,k-1){
		LL v=(mo-i)%mo;
		fd(j,k,1)c[j]=(c[j]*v+c[j-1])%mo;
		c[0]=c[0]*v%mo;
	}
	printf("%I64d\n",(solve(r+2)+mo-solve(l+1))%mo*inv[k]%mo);
	return 0;
}