#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
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
	if(ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int inf  = 1e+9;

int main(){
	int n=get(),now=0,low=-inf,lim=inf;
	fo(i,1,n){
		int v=get(),t=get();
		if (t==1)low=max(low,1900-now);
		else lim=min(lim,1899-now);
		now+=v;
	}
	if (lim==inf)printf("Infinity\n");
	else
		if (low>lim)printf("Impossible\n");
			else printf("%d\n",lim+now);
	return 0;
}