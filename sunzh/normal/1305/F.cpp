#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<map>
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
const double st=clock();
int n;
int a[200010];
int ans=0x3f3f3f3f;
int prime[1000010];
bool vis[1000010]; 
int cnt,num;
map<int,bool>mp;
int fc[1000010];
void pre_get_prime(){
	const int pre=1000000;
	for(int i=2;i<=pre;++i){
		if(!vis[i]) prime[++cnt]=i;
		for(int j=1;prime[j]*i<=pre&&j<=cnt;++j){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break ;
		}
	}
}
void get_prime(int x){
	int t=x;
	for(int i=1;i<=cnt&&prime[i]<=x;++i){
		if(t%prime[i]==0){
			t/=prime[i];fc[++num]=prime[i];
		}
		while(t%prime[i]==0) t/=prime[i];
	}
	if(t!=1) fc[++num]=t;
}
void solve(int x){
	if(x==0||x==1) return ;
	int sum=0;
	for(int i=1;i<=n;++i){
		if(a[i]<x) sum=sum+x-a[i];
		else sum=sum+min(a[i]-(a[i]/x)*x,(a[i]/x+1)*x-a[i]);
		if(sum>=ans) return ;
	}
	ans=min(ans,sum);
}
signed main(){
	srand(998244353);
	pre_get_prime();
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	
		mp.clear();
		mp[0]=1;num=0;
		for(int i=1;i<=10&&i<=(n-1);++i){
			int k=(rand()*10+rand())%(n+1);
			while(mp.count(k)){
				k=(rand()*10+rand())%(n+1);
			}
			mp[k]=1;
			get_prime(a[k]);
			get_prime(a[k]+1);
			get_prime(a[k]-1);
		}
		sort(fc+1,fc+num+1);
		num=unique(fc+1,fc+num+1)-fc;
		for(int i=1;i<=num;++i) solve(fc[i]);
	
	printf("%d\n",ans);
}