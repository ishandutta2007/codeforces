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
bool vis[100010];
int prime[100010],near_p[100010];
int cnt1,cnt2;
int main(){
	for(int i=2;i<=100000;++i){
		if(!vis[i]){
			prime[++cnt1]=i;
			for(int j=1;j<cnt1&&prime[j]*i<=100000;++j) near_p[++cnt2]=prime[j]*i;
		}
		for(int j=1;j<=cnt1&&prime[j]*i<=100000;++j){
			vis[prime[j]*i]=1;
			if(i%prime[j]==0) break ;
		}
	}
	sort(near_p+1,near_p+cnt2+1);
	int minsum=near_p[1]+near_p[2]+near_p[3];
	T=read();
	while(T--){
		n=read();
		if(n<=minsum) printf("NO\n");
		else {
			printf("YES\n");
			if(n-minsum==6) printf("5 6 10 15\n");
			else if(n-minsum==10) printf("5 6 14 15\n");
			else if(n-minsum==14) printf("6 7 10 21\n");
			else printf("6 10 14 %d\n",n-minsum);
		}
	}
	return 0;
}