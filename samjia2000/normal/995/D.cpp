#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int L = (1<<18)+5;

int n;
int r;
int c[L];

int main(){
	n=get();r=get();
	fo(i,0,(1<<n)-1)c[i]=get();
	LL s=0;
	fo(i,0,(1<<n)-1)s+=c[i];
	printf("%.9lf\n",1.0*s/(1<<n));
	fo(cas,1,r){
		int x=get(),v=get()-c[x];
		c[x]+=v;
		s+=v;
		printf("%.9lf\n",1.0*s/(1<<n));		
	}
	return 0;
}