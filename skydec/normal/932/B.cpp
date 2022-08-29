#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=1000005;
int f[N];
int ans[11][N];
int get(int x){
	int w=1;
	while(x){
		if(x%10)w*=(x%10);
		x/=10;
	}
	return w;
}
int n=1000000;
int main(){
	rep(i,1,n){
		if(i<10)f[i]=i;
		else f[i]=f[get(i)];
	}
	rep(j,1,9)rep(i,1,n)ans[j][i]=ans[j][i-1]+(f[i]==j);
	int Q;scanf("%d",&Q);
	while(Q--){
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",ans[k][r]-ans[k][l-1]);
	}
	return 0;
}