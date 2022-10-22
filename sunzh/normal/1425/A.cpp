#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
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
map<int,int>ma;
int T;
int n;
int cnt;
int dfs(int x){
	if(ma.count(x)) return ma[x];
	int res=0;
	if(x&1){
		res=x-dfs(x-1);
	}
	else{
		if(((x>>1ll)&1ll)^1ll) res=max(res,x-dfs(x-1));
		else res=x-dfs(x>>1ll);
	}
	if(ma.size()<=1e5) ma[x]=res;
	return res;
}
signed main(){
	T=read();
	ma[1ll]=ma[2ll]=1;ma[4ll]=3;
	while(T--){
		n=read();
		printf("%lld\n",dfs(n));
	}
	return 0;
}