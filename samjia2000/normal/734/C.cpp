#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int get(){
	char ch;
	int s=0;
	bool bz=0;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-')bz=1;else s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	if (bz)return -s;
	return s;
}

const int N = 2e+5+10;

typedef long long LL;

int n,m,k;
int x,s;
int a[N],b[N];
int c[N],d[N];
LL ans;

LL getv(LL x,LL s){
	int l=1,r=k,w=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (d[mid]>s)r=mid-1;
		else{
			l=mid+1;
			w=mid;
		}
	}
	return LL(n-c[w])*x;
}

int main(){
	n=get();m=get();k=get();
	x=get();s=get();
	fo(i,1,m)a[i]=get();
	fo(i,1,m)b[i]=get();
	fo(i,1,k)c[i]=get();
	fo(i,1,k)d[i]=get();
	ans=LL(x)*n;
	LL v=getv(x,s);
	if (ans>v)ans=v;
	fo(i,1,m)
	if (s>=b[i]){
		v=getv(a[i],s-b[i]);
		if (ans>v)ans=v;
	}
	printf("%I64d\n",ans);
	return 0;
}