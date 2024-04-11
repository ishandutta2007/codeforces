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

const int N = 1e6+1e3+5;

LL a;
int pri[N],k;
bool bz[N];

bool can(LL x){
	fo(i,1,k){
		if (x<1ll*pri[i]*pri[i])return 1;
		if (x%pri[i]==0)return 0;
	}
	return 1;
}

int getans(int x,LL v){
	if (v==1)return 1;
	if (v<pri[x]+1)return 0;
	if (v<1ll*pri[x]*pri[x]+1)return can(v-1);
	int ret=getans(x+1,v);
	for(LL now=pri[x];now<v;now=now*pri[x]){
		if (v%(now+1)==0)ret=ret+getans(x+1,v/(now+1));
	}
	return ret;
}

int main(){
	fo(i,2,1e6+1e3)
	if (!bz[i]){
		pri[++k]=i;
		fo(j,2,1e6/i)bz[i*j]=1;
	}
	scanf("%I64d",&a);
	printf("%d\n",getans(1,a));
	return 0;
}