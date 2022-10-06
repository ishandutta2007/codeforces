#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
#define rep(i,a,b) for (int i=a; i<=b; i++)
using namespace std;



inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	int n; read(n);
	printf("%d",(n-1)>>1);
	return 0;
}