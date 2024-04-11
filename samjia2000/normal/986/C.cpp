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

const int L = (1<<22)+5;

int n,m;
bool bz[L];
int fa[L];
struct status{
	int mx,mi;
}f[L];

int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}

void merge(int x,int y){
	int fx=getfather(x),fy=getfather(y);
	fa[fx]=fy;
}

int main(){
	n=get();m=get();
	fo(i,1,m){
		int x=get();
		bz[x]=1;
		fa[x]=x;
	}
	int siz=m;
	while(1){
		int psiz=siz;
		fo(i,0,(1<<n)-1)f[i].mx=f[i].mi=-1;
		fo(i,0,(1<<n)-1)
		if (bz[i]){
			getfather(i);
			f[i].mx=f[i].mi=i;
		}
		for(int i=1,d=1;i<(1<<n);i<<=1,d++)
			for(int j=0;j<(1<<n);j+=(i<<1))
				for(int k=0;k<i;k++)
				if (f[j+k].mx!=-1){
					if (f[i+j+k].mx==-1||fa[f[j+k].mx]>fa[f[i+j+k].mx])f[i+j+k].mx=f[j+k].mx;
					if (f[i+j+k].mi==-1||fa[f[j+k].mi]<fa[f[i+j+k].mi])f[i+j+k].mi=f[j+k].mi;
				}
		fo(i,0,(1<<n)-1)
		if (bz[i]){
			int fi=getfather(i);
			if (f[i^((1<<n)-1)].mx!=-1)merge(i,f[i^((1<<n)-1)].mx);
			if (f[i^((1<<n)-1)].mi!=-1)merge(i,f[i^((1<<n)-1)].mi);
		}
		siz=0;
		fo(i,0,(1<<n)-1)
		if (bz[i]){
			int fi=getfather(i);
			if (fi==i)siz++;
		}
		if (psiz==siz)break;
	}
	printf("%d\n",siz);
	return 0;
}