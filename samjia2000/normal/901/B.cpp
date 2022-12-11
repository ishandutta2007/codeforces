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

const int N = 155;

int n;
int a[N],b[N],tmp[N];

int main(){
	n=get();
	a[1]=1;a[0]=0;
	b[0]=1;
	fo(deg,2,n){
		fo(i,0,deg-1)tmp[i]=a[i];
		fd(i,deg,1)a[i]=a[i-1];
		a[0]=0;
		fo(i,0,deg-2)a[i]=a[i]^b[i];
		fo(i,0,deg-1)b[i]=tmp[i];
	}
	printf("%d\n",n);
	fo(i,0,n)printf("%d ",a[i]);putchar('\n');
	printf("%d\n",n-1);
	fo(i,0,n-1)printf("%d ",b[i]);
	return 0;
}