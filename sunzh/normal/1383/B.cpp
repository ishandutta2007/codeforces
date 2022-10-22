#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int T;
int n;
int a[100010];
signed main(){
	T=read();
	while(T--){
		int n=read();
		int x=0,y=0;
		for(int i=1;i<=n;++i) a[i]=read(),x^=a[i];
		if(x==0){
			printf("DRAW\n");continue ;
		}
		for(int k=32;k>0;--k){
			x=y=0;
			for(int i=1;i<=n;++i){
				if(a[i]&(1<<k-1)) ++x;
				else ++y;
			}
			if((x&3)==3){
				if(y&1) {
					printf("WIN\n");
					break ;
				}
				else {
					printf("LOSE\n");break ;
				}
			} 
			else if(x&1){
				printf("WIN\n");
				break ;
			}
		}
	}
	return 0;
}