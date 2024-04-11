#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T,n,a,b;
int main(){
	T=read();
	while(T--){
		n=read(),a=read(),b=read();
		if(abs(a-b)>1||a+b+2>n){
			printf("-1\n");continue ;
		}
		if(a>b){
			int used=a+b+1;
			for(int i=1;i+used<=n;++i) printf("%d ",i);
			for(int i=1;i<=a;++i) printf("%d %d ",n-used+i*2,n-used+i*2-1);printf("\n");
		}
		else if(a==b){
			int used=a+b+1;
			for(int i=1;i+used<=n;++i) printf("%d ",i);
			for(int i=1;i<=a;++i) printf("%d %d ",n-used+i*2,n-used+i*2-1);printf("%d\n",n);
		}
		else{
			for(int i=1;i<=b;++i) printf("%d %d ",i*2,i*2-1);
			for(int i=2*b+1;i<=n;++i) printf("%d ",i);printf("\n");
		}
	}
}