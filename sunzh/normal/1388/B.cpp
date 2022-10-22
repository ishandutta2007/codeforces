#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
int n;
int main(){
	T=read();
	while(T--){
		n=read();
		int num0=(n-1>>2)+1;
		for(int i=1;i<=n-num0;++i) putchar('9');
		for(int i=1;i<=num0;++i) putchar('8');
		putchar('\n');
	}
	return 0;
}