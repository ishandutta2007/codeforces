#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define Maxn 35
#define ll long long
ll f[Maxn+5][2][2];
int n,m;
int find(int x,int n){
	return ((1<<x)&n)>0?1:0;
}
ll dfs(int x,int a,int b){
	if(f[x][a][b]!=-1){
		return f[x][a][b];
	}
	if(x==0){
		if(a==0&&b==0){
			return f[x][a][b]=3;
		}
		if(a==1&&b==1){
			return f[x][a][b]=1+(n&1)+(m&1);
		}
		if(a==0&&b==1){
			return f[x][a][b]=2+(m&1);
		}
		return f[x][a][b]=2+(n&1);
	}
	ll &ans=f[x][a][b];
	ans=0;
	if(a==0&&b==0){
		return ans=dfs(x-1,0,0)*3;
	}
	if(a==1&&b==1){
		if(find(x,n)&&(find(x,m))){
			ans=dfs(x-1,0,0)+dfs(x-1,1,0)+dfs(x-1,0,1);
		}
		else if(find(x,n)){
			ans=dfs(x-1,0,1)+dfs(x-1,1,1);
		}
		else if(find(x,m)){
			ans=dfs(x-1,1,0)+dfs(x-1,1,1);
		}
		else{
			ans=dfs(x-1,1,1);
		}
		return ans;
	}
	if(a==1&&b==0){
		if(find(x,n)){
			ans=dfs(x-1,0,0)*2+dfs(x-1,1,0);
		}
		else{
			ans=dfs(x-1,1,0)*2;
		}
		return ans;
	}
	if(find(x,m)){
		ans=dfs(x-1,0,0)*2+dfs(x-1,0,1);
	}
	else{
		ans=dfs(x-1,0,1)*2;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	int l,r;
	ll ans_1,ans_2,ans_4;
	while(t--){
		scanf("%d%d",&l,&r);
		if(l==0){
			memset(f,-1,sizeof f);
			n=r,m=r;
			cout<<dfs(30,1,1)<<endl;
			continue;
		}
		memset(f,-1,sizeof f);
		n=r,m=r;
		ans_1=dfs(30,1,1);
		memset(f,-1,sizeof f);
		n=l-1,m=r;
		ans_2=dfs(30,1,1);
		memset(f,-1,sizeof f);
		n=l-1,m=l-1;
		ans_4=dfs(30,1,1);
		cout<<ans_1-ans_2*2+ans_4<<endl;
	}
	return 0;
}