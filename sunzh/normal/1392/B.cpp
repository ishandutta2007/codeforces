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
int n,k;
int d;
int a[200010];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		d=-0x7f7f7f7f;
		for(int i=1;i<=n;++i) a[i]=read(),d=max(d,a[i]);
		for(int i=1;i<=n;++i) a[i]=d-a[i];
		if(k&1){
			for(int i=1;i<=n;++i) printf("%d ",a[i]);
			putchar('\n');
		}
		else{
			d=-0x7f7f7f7f;
			for(int i=1;i<=n;++i) d=max(d,a[i]);
			for(int i=1;i<=n;++i) a[i]=d-a[i];
			for(int i=1;i<=n;++i) printf("%d ",a[i]);
			putchar('\n');
		}
	}
	return 0;
}