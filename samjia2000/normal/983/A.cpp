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

LL gcd(LL x,LL y){return y==0?x:gcd(y,x%y);}

int main(){
	for(int T=get();T;T--){
		LL p,q,b;
		scanf("%lld%lld%lld",&p,&q,&b);
		if (p==0){printf("Finite\n");continue;}
		LL d=gcd(p,q);
		q/=d;
		LL v=gcd(q,b);
		for(;v>1;){
			for(;q%v==0;)q=q/v;
			v=gcd(q,b);
		}
		if (q==1)printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}