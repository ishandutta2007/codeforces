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
int a[200010];
bool flag;
int main(){
	T=read();
	while(T--){
		flag=0;
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();if(i>1&&a[i]!=a[i-1]) flag=1;
		}
		if(flag) printf("1\n");
		else printf("%d\n",n);
	}
	return 0;
}