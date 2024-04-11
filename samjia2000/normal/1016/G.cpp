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

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 2e5+5;
const int L = (1<<16)+5;

LL absll(LL x){return x<0?-x:x;}
LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}

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
	x=x%mo;
	for(;tim;tim/=2,x=multi(x,x,mo))
	if (tim&1)ret=multi(ret,x,mo);
	return ret;
}

struct Prime_Divisor{
		LL x,tim;
};
bool cmp(Prime_Divisor a,Prime_Divisor b){return a.x<b.x;}

struct Number{
	LL val;
	int k;
	Prime_Divisor a[100];
	
	LL f(LL x,LL mo){
		long double d=1;
		d=(d*x*x+1)/mo;
		LL t=d;
		LL ret=x*x+1-t*mo;
		ret=(ret%mo+mo)%mo;
		return ret;
	}
	
	bool miller_rabin(LL x,LL s,LL n){
		if (x==1||x==n-1)return 1;
		fo(i,1,s-1){
			x=multi(x,x,n);
			if (x==n-1)return 1;
			if (x==1)return 0;
		}
		return x==n-1||x==1;
	}
	
	bool is_prime(LL n){
		if (n==2||n==3||n==5||n==7||n==11)return 1;
		if (n%2==0||n%3==0||n%5==0||n%7==0)return 0;
		LL now=n-1,s=0;
		for(;now%2==0;now/=2,s++);
		fo(tim,1,5){
			ui key=getrand()+1;
			key=key%n;
			while(!key)key=(getrand()+1)%n;
			if (!miller_rabin(quickmi(key,now,n),s,n))return 0;
		}
		return 1;
	}
	
	void pollard_rho(LL n){
		if (is_prime(n)){
			k++;
			a[k].x=n;
			return;
		}
		LL ret=1,siz=2,x_fixed=getrand();
		LL x=x_fixed;
		while(ret==1){
			for(int count=1;count<=siz&&ret<=1;count++){
				x=f(x,n);
				ret=gcd(absll(x-x_fixed),n);
			}
			siz=siz*2;
			x_fixed=x;
		}
		pollard_rho(ret);
		if (ret!=n)pollard_rho(n/ret);
	}
	
	void get_divisors(){
		k=0;
		pollard_rho(val);
		sort(a+1,a+1+k,cmp);
		fo(i,1,k)a[i].tim=0;
		int k_=1;
		a[1].tim=1;
		fo(i,2,k){
			if (a[i].x>a[i-1].x)a[++k_].x=a[i].x;
			a[k_].tim++;
		}
		k=k_;
	}
}X,Y;
int n;
LL a[N];
bool can[N];
int cnt[L];

int main(){
	seed=75748745;
	n=get();
	scanf("%I64d%I64d",&X.val,&Y.val);
	if (Y.val%X.val!=0)return printf("0\n"),0;
	fo(i,1,n)scanf("%I64d",&a[i]);
	Y.get_divisors();
	X.k=Y.k;
	LL now=X.val;
	fo(i,1,Y.k){
		X.a[i]=Y.a[i];
		X.a[i].tim=0;
		while(now%X.a[i].x==0)now/=X.a[i].x,X.a[i].tim++;
	}
	int k=X.k;
	fo(i,1,n)can[i]=1;
	int used=0;
	fo(x,1,X.k)
	if (X.a[x].tim==Y.a[x].tim)used|=(1<<(x-1));
	fo(i,1,n){
		LL now=a[i];
		int id=0;
		fo(x,1,k){
			LL tim=0;
			while(now%X.a[x].x==0)now/=X.a[x].x,tim++;
			if(tim<X.a[x].tim){id=-1;break;}
			if(tim>X.a[x].tim)id|=(1<<(x-1));
		}
		if (id!=-1)cnt[id-(id&used)]++;
	}
	for(int i=1;i<(1<<k);i<<=1)
		for(int j=0;j<(1<<k);j+=(i<<1))
			for(int x=0;x<i;x++)cnt[i+j+x]+=cnt[j+x];
	LL ans=0;
	fo(i,1,n){
		LL now=a[i];
		int id=0;
		fo(x,1,k){
			LL tim=0;
			while(now%Y.a[x].x==0)now/=Y.a[x].x,tim++;
			if (tim>Y.a[x].tim){id=-1;break;}
			if (tim<Y.a[x].tim)id|=(1<<(x-1));
		}
		if (now>1)id=-1;
		if (id!=-1)ans=ans+cnt[((1<<k)-1)^(id-(id&used))];
	}
	cout<<ans<<endl;
	return 0;
}