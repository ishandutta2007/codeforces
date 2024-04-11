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
int a[1010];
bool flag;
int main(){
	T=read();
	while(T--){
		flag=0;
		int x,y,z;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=2;i<n;++i){
			x=z=-1;
			y=i;
			for(int j=1;j<i;++j){
				if(a[j]<a[i]){
					x=j;
					break ;
				}
			}
			if(x==-1) continue ;
			for(int j=i+1;j<=n;++j){
				if(a[i]>a[j]){
					z=j;
					break ;
				}
			}
			if(z==-1) continue ;
			flag=1;
			printf("YES\n");
			printf("%d %d %d\n",x,y,z);
			break ;
		}
		if(!flag) printf("NO\n");
	}
}