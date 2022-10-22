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
#include<random>
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
int s[100010],dt[100010];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=k;++i) s[i]=read();
		int pr=n-k+1;
		for(int i=1;i<k;++i) dt[i]=s[i+1]-s[i];
		bool f=1;
		for(int i=1;i<k-1;++i) if(dt[i+1]<dt[i]) f=0;
		if(k>1){
			if(s[1]>1ll*pr*dt[1]) f=0;
		}
		if(!f){
			printf("NO\n");continue ;
		}
		printf("YES\n");
	}
}