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

const int mo = 1e+9+7;
const int MAXN = 1048600;

LL val[MAXN];
int n;
int N;

void FWT(LL *a){
	for(int now=N;now>=2;now>>=1){
		int half=now/2;
		fo(i,0,half-1){
			for(int j=i;j<N;j+=now){
				LL l=a[j],r=a[j+half];
				a[j]=(l+mo-r)%mo;
				a[j+half]=(l+r)%mo;
			}
		}
	}
}

void IFWT(LL *a){
	LL ny=(mo+1)/2;
	for(int now=2;now<=N;now<<=1){
		int half=now/2;
		fo(i,0,half-1){
			for(int j=i;j<N;j+=now){
				LL l=a[j],r=a[j+half];
				a[j]=(l+r)*ny%mo;
				a[j+half]=(r+mo-l)*ny%mo;
			}
		}
	}
}

int main(){
	n=get();
	N=(1<<n);
	fo(i,0,(1<<n)-1){
		char ch;
		while(ch=getchar(),ch<'0'||ch>'1');
		val[i]=ch-'0';
	}
	FWT(val);
	fo(i,0,(1<<n)-1)val[i]=val[i]*val[i]%mo;
	IFWT(val);
	LL ans=0;
	fo(i,0,(1<<n)-1){
		int cnt=0;
		fo(j,0,n-1)
		if (((1<<j)&i)==0)cnt++;
		ans=(ans+val[i]*(1<<cnt)%mo)%mo;
	}
	ans=ans*3%mo;
	printf("%I64d\n",ans);
	return 0;
}