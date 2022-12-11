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

const int N = 200010;
const int mo =1e+9+7;

LL f[N];
int n;
int a[N];
LL js[N],ny[N];

LL quickmi(LL x,LL tim){
	LL ans=1;
	while(tim){
		if (tim%2)ans=ans*x%mo;
		x=x*x%mo;
		tim/=2;
	}
	return ans;
}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	if (n==1)printf("%d\n",a[1]);
	if (n==2)printf("%d\n",(a[1]+a[2])%mo);
	if (n==3)printf("%d\n",(1ll*a[1]+2*a[2]+mo-a[3])%mo);
	if (n==4)printf("%d\n",(1ll*a[1]+a[3]-a[2]-a[4]+mo*2)%mo);
	if (n>4){
		js[0]=1;
		fo(i,1,200000)js[i]=js[i-1]*i%mo;
		ny[200000]=quickmi(js[200000],mo-2);
		fd(i,199999,0)ny[i]=ny[i+1]*(i+1)%mo;
		int lst=(n-1)/4*2;
		fo(i,0,lst)f[i*2+1]=js[lst]*ny[i]%mo*ny[lst-i]%mo;
		lst=lst*2+1;
		fo(i,lst+1,n){
			if (i%4==0)
			{fd(j,i,1)
			if (j%2==0)f[j]=(f[j-1]-f[j]+mo)%mo;
			else f[j]=(f[j-1]+f[j])%mo;
			}
			else
			{fd(j,i,1)
			if (j%2)f[j]=(f[j]-f[j-1]+mo)%mo;
			else f[j]=(f[j]+f[j-1])%mo;
			}
		}
		LL ans=0;
		fo(i,1,n)ans=(ans+f[i]*a[i]%mo)%mo;
		printf("%I64d\n",ans);
	}
	return 0;
}