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
#define se second
#define fi first

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

const int N = 32;

int n,L;
LL c[N];

LL minll(LL x,LL y){return x<y?x:y;}

LL calc(LL v){
	LL tmp=0;
	fd(i,30,0)
	if (v>=c[i]){
		v=v-c[i];
		tmp=tmp|(1<<i);
	}
	return tmp;
}

int main(){
	n=get();L=get();
	fo(i,0,n-1)c[i]=get();
	fo(i,n,30)c[i]=4e18;
	fo(i,1,30)c[i]=minll(c[i],c[i-1]*2);
	LL ans=0,l=0,r=4e+18;
	while(l<=r){
		LL mid=(l+r)/2;
		if (calc(mid)>=L)ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%I64d\n",ans);
	return 0;
}