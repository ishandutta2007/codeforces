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
		if(n==1) printf("1\n");
		else if(n==2) printf("2\n");
		else printf("%d\n",1+(n>>1));
	}
	return 0;
}