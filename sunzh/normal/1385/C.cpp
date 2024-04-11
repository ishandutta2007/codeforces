#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	return x*f;
}
int T;
int n;
int a[2000010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		int p=n;
		while(p>1&&a[p-1]>=a[p]){
			--p;
		}
		while(p>1&&a[p-1]<=a[p]) --p;
		printf("%d\n",p-1);
	}
	return 0;
}