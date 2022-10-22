#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int prime[1000010];
int sum[1000010];
bool vis[1000010];
int T;
int cnt;
int n;
void getprime(){
	for(int i=2;i<=1000000;++i){
		if(!vis[i]) prime[++cnt]=i,sum[i]=1;
		for(int j=1;prime[j]*i<=1000000&&j<=cnt;++j){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break ;
		}
	}
	for(int i=1000000;i>=1;--i) sum[i]+=sum[i+1]; 
}
int main(){
	getprime();
	T=read();
	while(T--){
		n=read();
		int x=ceil(sqrt(n+1));
		printf("%d\n",1+sum[x]-sum[n+1]);
	}
}