#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
int n;
int fa[N];vector<int>go[N];
int s[N];int dep[N];
LL ans=0;
int sz[N];
int a[N];
void dfs(int x){
	for(int y:go[x])dfs(y);
	dep[x]=dep[fa[x]]+1;
	if(s[x]==-1){
		if(!go[x].size()){
			a[x]=0;
		}
		else{
			int t=1e9;
			for(int y:go[x])t=min(t,s[y]);
			a[x]=t-s[fa[x]];
			for(int y:go[x])a[y]=s[y]-s[fa[x]]-a[x];
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		scanf("%d",&fa[i]);
		go[fa[i]].pb(i);
	}
	rep(i,1,n)scanf("%d",&s[i]);
	a[1]=s[1];
	dfs(1);
	rep(i,1,n)if(a[i]<0){
		printf("-1\n");
		return 0;
	}
	rep(i,1,n){
		if(s[i]==-1){
			s[i]=s[fa[i]]+a[i];
		}
		else{
			if(s[i]!=s[fa[i]]+a[i]){
				printf("-1\n");
				return 0;
			}
		}
	}
	LL ans=0;
	rep(i,1,n)ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}