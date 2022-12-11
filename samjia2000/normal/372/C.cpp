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

const int N= 150005;
const LL INF = 1e14;

int n,m,d;
LL val[N],tmp[N];
int que[N];

LL maxll(LL x,LL y){return x>=y?x:y;}

int main(){
	n=get();m=get();d=get();
	int lst=0;
	fo(cas,1,m){
		int a=get(),b=get(),t=get();
		LL v=1ll*(t-lst)*d;
		int len;
		if (v>n)len=n;else len=(t-lst)*d;
		lst=t;
		int he=1,ta=0;
		fo(i,1,n)tmp[i]=-INF;
		fo(i,1,n){
			while(he<=ta&&que[he]<i-len)he++;
			if (he<=ta)tmp[i]=maxll(tmp[i],val[que[he]]);
			while(he<=ta&&val[que[ta]]<=val[i])ta--;
			que[++ta]=i;
		}
		he=1,ta=0;
		fd(i,n,1){
			while(he<=ta&&que[he]>i+len)he++;
			if (he<=ta)tmp[i]=maxll(tmp[i],val[que[he]]);
			while(he<=ta&&val[que[ta]]<=val[i])ta--;
			que[++ta]=i;
		}
		fo(i,1,n)val[i]=maxll(val[i],tmp[i]);
		fo(i,1,n)val[i]=val[i]+b-abs(a-i);
	}
	LL ans=-INF;
	fo(i,1,n)ans=maxll(ans,val[i]);
	printf("%I64d\n",ans);
	return 0;
}