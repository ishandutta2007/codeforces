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
int a[100010];
int ans;
int main(){
	T=read();
	while(T--){
		ans=-1;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i){
			if(a[i]>1){
				ans=i;
				break ;
			}
		}
		if(ans==-1){
			if(n%2==1) printf("First\n");
			else printf("Second\n");
		}
		else {
			if(ans%2==1) printf("First\n");
			else printf("Second\n");
		}
	}
}