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

int v1[11],v0[11];

int main(){
	int n=get();
	int now=1023;
	fo(j,0,9)v1[j]=1,v0[j]=0;
	fo(i,1,n){
		char ch;
		while(ch=getchar(),ch!='&'&&ch!='|'&&ch!='^');
		int x=get();
		if (ch=='&'){
			fo(j,0,9)
			if ((x&(1<<j))==0)v1[j]=v0[j]=0;
		}
		if (ch=='|'){
			fo(j,0,9)
			if ((x&(1<<j))>0)v1[j]=0,v0[j]=1;
		}	
		if (ch=='^'){
			fo(j,0,9)
			if ((x&(1<<j))>0)v0[j]^=1;
		}
	}
	printf("2\n");
	int tmp=0;
	fo(i,0,9)
	if (v1[i])tmp=tmp+(1<<i);
	printf("& %d\n",tmp);
	tmp=0;
	fo(i,0,9)
	if (v0[i])tmp+=1<<i;
	printf("^ %d\n",tmp);
	return 0;
}