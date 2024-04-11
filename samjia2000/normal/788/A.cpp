#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<set>
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

const int N = 100010;

int a[N];
int n;
LL v0,v1,ans;

LL maxll(LL x,LL y){
	if (x>y)return x;
	return y;
}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n-1)a[i]=abs(a[i]-a[i+1]);
	for(int i=2;i<n;i+=2)a[i]=-a[i];
	fd(i,n-1,1){
		v0=v0+a[i];
		v1=v1+a[i];
		if (v0<0)v0=0;
		if (v1>0)v1=0;
		if (i%2)ans=maxll(ans,v0);
		else ans=maxll(ans,-v1);
	}
	printf("%I64d\n",ans);
	return 0;
}