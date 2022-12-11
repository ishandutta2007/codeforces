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
typedef unsigned int ui;

ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}

const int N = 5e5+5;

struct Prime_divisor{
	LL x,tim;
}pri[105];
int k;
LL m,len;
LL d[N];
int n;
map<LL,LL>id,phi;
LL ad[N],mu[N];
int u;

void getall(int x,LL now,int v,LL phy){
	if (x>k){
		d[++n]=now;
		id[now]=n;
		phi[now]=phy;
		if (v!=0){
			ad[++u]=now;
			mu[u]=v;
		}
		return;
	}
	for(int i=0;i<=pri[x].tim;i++,now*=pri[x].x,phy*=pri[x].x){
		getall(x+1,now,v*(i==0?1:(i==1?-1:0)),i==0?phy:phy/pri[x].x*(pri[x].x-1));
	}
}

LL g[N],f[N];

struct divisors{
	int n;
	LL a[105];
	
	LL & operator [](int x){return a[x];}
}A;

LL multi(LL x,LL y,LL mo){
	long double d=1;
	d=d*x*y/mo;
	LL t=d;
	LL ret=x*y-t*mo;
	ret=(ret%mo+mo)%mo;
	return ret;
}

LL quickmi(LL x,LL tim,LL mo){
	LL ret=1;
	x%=mo;
	for(;tim;tim/=2,x=multi(x,x,mo))
	if (tim&1)ret=multi(ret,x,mo);
	return ret;
}

LL func(LL x,LL n){
	return (multi(x,x,n)+1)%n;
}

bool miller_rabin(LL v,LL s,LL mo){
	if (v==1||v==mo-1)return 1;
	fo(i,1,s){
		v=multi(v,v,mo);
		if (v==mo-1&&i<s)return 1;
		if (v==1)return 0;
	}
	return v==1;
}

bool isprime(LL n){
	if (n==2||n==3||n==5||n==7)return 1;
	if (n%2==0||n%3==0||n%5==0||n%7==0)return 0;
	LL s=0,x=n-1;
	for(;x%2==0;x/=2,s++);
	fo(i,1,5){
		LL v=getrand()%(n-1)+1;
		if (!miller_rabin(quickmi(v,x,n),s,n))return 0;
	}
	return 1;
}

LL absll(LL x){return x<0?-x:x;}

LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}

void getdivisors(LL n){
	if (n==1)return;
	if (isprime(n)){
		A[++A.n]=n;
		return;
	}
	LL x_fixed=getrand()%n+1,circle=2;
	LL x=x_fixed,ret=1;
	while(ret==1){
		for(LL i=0;i<circle&&ret==1;i++){
			x=func(x,n);
			ret=gcd(absll(x-x_fixed),n);
		}
		x_fixed=x;
		circle<<=1;
	}
	getdivisors(ret);
	getdivisors(n/ret);
}

LL getlen(LL mo,LL x){
	LL len=phi[mo];
	A.n=0;
	getdivisors(len);
	fo(i,1,A.n){
		if (quickmi(x,len/A[i],mo)==1)len/=A[i];
	}
	return len;
}

int main(){
	seed=83727232;
	cin>>m>>len;
	LL x=m;
	fo(i,2,1e7)
	if ((x%i)==0){
		pri[++k].x=i;
		pri[k].tim=0;
		while(x%i==0){
			x/=i;
			pri[k].tim++;
		}
	}
	if (x>1){
		pri[++k].x=x;
		pri[k].tim=1;
	}
	getall(1,1,1,1);
	fo(i,1,n)g[i]=m/d[i]-1;
	fo(i,1,n)f[i]=g[i];
	fo(v,1,k)
		fo(i,1,n)
		if (d[i]%pri[v].x==0){
			int x=id[d[i]/pri[v].x];
			f[x]=f[x]-f[i];
		}
	LL ans=0;
	fo(i,1,n)
	if (f[i]){
		ans=ans+f[i]/getlen(m/d[i],len);
	}
	ans++;
	cout<<ans<<endl;
	return 0;
}