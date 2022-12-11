#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int N = 100005;
 
int n;
char s[N];
int a[N];
int mo;
int g0;

bool isprime(int mo){
	fo(i,2,sqrt(mo))
	if (mo%i==0)return 0;
	return 1;
}

int pri[N],k;
LL quickmi(LL x,LL tim,LL mo){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

void getroot(int mo){
	k=0;
	int now=mo-1;
	fo(i,2,sqrt(mo-1))
	if (now%i==0){
		pri[++k]=i;
		while(now%i==0)now=now/i;
	}
	fo(i,2,100){
		bool pd=1;
		fo(x,1,k)pd&=(quickmi(i,(mo-1)/pri[x],mo)!=1);
		if (pd){g0=i;break;}
	}
}

int main(){
	n=get();
	scanf("%s",s+1);
	fo(i,1,n)a[i]=s[i]-'0';
	mo=int(5e8/n)*n+1;
	while(!isprime(mo))mo+=n;
	getroot(mo);
	g0=quickmi(g0,(mo-1)/n,mo);
	LL sum=0;
	LL now=1;
	fo(i,1,n){
		sum=(sum+now*a[i])%mo;
		now=now*g0%mo;
	}
	if (!sum)printf("YES\n");
	else printf("NO\n");
	return 0;
}