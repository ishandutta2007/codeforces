#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
using namespace std;

int a,b;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(a); read(b);
	if (a==b) {
	//	int x=sqrt(a);printf("%d %d %d\n",a,b,x);
		rep(i,2,sqrt(a)) if (a%i==0) {printf("%d",i); return 0;}
		printf("%d",a);
	}
	else printf("2");
	return 0;
}