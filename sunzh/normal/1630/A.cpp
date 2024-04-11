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
int T;
int n,k;
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		if(n==4&&k==3) printf("-1\n");
		else{
			if(k==n-1){
				for(int i=3;i<n;++i) if(i<n-1-i) printf("%d %d\n",i,n-1-i);
				printf("0 2\n1 %d\n%d %d\n",n-3,n-2,n-1);continue ;
			}
			for(int i=0;i<n;++i){
				if(i!=0&&i!=k&&i<n-1-i&&i!=n-1&&i!=n-1-k) printf("%d %d\n",i,n-1-i);
			}
			if(k!=0) printf("%d %d\n",k,n-1);
			printf("%d %d\n",0,n-1-k);
		}
	}
}