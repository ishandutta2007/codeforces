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
const int N=310000;
int a[N],b[N];
int go[N*32][2];
int tot;
int sum[N*32];
int n;
void ins(int now,int x,int v,int vv){
	sum[now]+=vv;
	if(v==-1)return;
	int s=((x&(1<<v))>0);
	if(!go[now][s])go[now][s]=++tot;
	ins(go[now][s],x,v-1,vv);
}
int ask(int now,int x,int v){
	if(v==-1)return 0;
	int s=((x&(1<<v))>0);
	if(sum[go[now][s]]){
		return ask(go[now][s],x,v-1);
	}
	else return ask(go[now][s^1],x,v-1)+(1<<v);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	tot=1;
	rep(i,1,n)ins(1,b[i],29,1);
	rep(i,1,n){
		int w=ask(1,a[i],29);
		printf("%d ",w);
		ins(1,a[i]^w,29,-1);
	}
	puts("");
	return 0;
}