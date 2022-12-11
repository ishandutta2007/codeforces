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

const int N = 1e+5+5;
const int mo = 1e+9+7;

map<int,int>idx,idy;
int n,k;
int fa[N*2];
int siz[N*2];
bool bz[N*2];

int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}

LL quickmi(LL x,LL tim){LL ans=1;for(;tim;tim/=2,x=x*x%mo)if (tim&1)ans=ans*x%mo;return ans;}

int main(){
	n=get();
	fo(i,1,2e+5)fa[i]=i,siz[i]=1;
	fo(i,1,n){
		int x=get(),y=get();
		if (!idx[x])idx[x]=++k;
		if (!idy[y])idy[y]=++k;
		x=idx[x];y=idy[y];
		int fx=getfather(x),fy=getfather(y);
		if (fx==fy)bz[fx]=1;
		else{
			fa[fy]=fx;
			siz[fx]+=siz[fy];
			bz[fx]|=bz[fy];
		}
	}
	LL ans=1;
	fo(i,1,k){
		int x=getfather(i);
		if (x==i){
			if (bz[x])ans=ans*quickmi(2,siz[x])%mo;
			else ans=ans*(quickmi(2,siz[x])-1)%mo;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}