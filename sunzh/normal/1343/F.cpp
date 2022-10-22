#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int a[210][210];
bool used[210];
int ans[210],pos[210];
bool check(){
	for(int i=2;i<=n;++i){
		for(int j=1;j<n;++j){
			if(used[j]) continue ;
			int x=-1,p=a[j][0];
			for(int k=1;k<=a[j][0];++k){
				if(!pos[a[j][k]]) x=a[j][k];
				else if(pos[a[j][k]]+a[j][0]-1>=i) --p;
			}
			if(p==1){
				used[j]=1;ans[i]=x,pos[x]=i;break ;
			}
		}
		if(!ans[i]) return 0;
	}
	return 1;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<n;++i){
			a[i][0]=read();
			for(int j=1;j<=a[i][0];++j) a[i][j]=read(); 
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) ans[j]=pos[j]=used[j]=0;
			ans[1]=i,pos[i]=1;
			if(check()) break ;
		}
		for(int i=1;i<=n;++i) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}