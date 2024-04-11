#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 200000
ll dp[2][Maxn+5];
int n,a[Maxn+5];
bool u[2][Maxn+5],v[2][Maxn+5];
ll dfs(int x,int sel){
	if(x<1||x>n) {
		return 0;
	}
	if(u[sel][x]){
		return v[sel][x]?dp[sel][x]:-1;
	}
	u[sel][x]=1;
	ll t=dfs(x+(sel?-a[x]:a[x]),sel^1);
	v[sel][x]=1;
	return dp[sel][x]=(~t?t+a[x]:t);
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		a[1]=i;
		cout<<(~dfs(a[1]+1,1)?dp[1][a[1]+1]+a[1]:-1)<<endl;
	}
	return 0;
}
////.,.,