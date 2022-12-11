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

int main(){
	int n=get();
	char ch;
	int t0=0,t1=0;
	while(ch=getchar(),ch!='A'&&ch!='D');
	if (ch=='A')t0++;else t1++;
	while(ch=getchar(),ch=='A'||ch=='D'){
		if (ch=='A')t0++;else t1++;
	}
	if (t0>t1)printf("Anton\n");
	if (t0<t1)printf("Danik\n");
	if (t0==t1)printf("Friendship\n");
	return 0;
}