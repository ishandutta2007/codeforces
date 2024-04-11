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
const int N=1005;
int Q(int a,int b){
	printf("? %d %d\n",a,b);
	fflush(stdout);
	int x;scanf("%d",&x);
	return x;
}
int n;
int du[N];
vector<int> go[N];
int q[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int a,b;scanf("%d%d",&a,&b);
		go[a].pb(b);
		go[b].pb(a);
		du[a]++;
		du[b]++;
	}
	rep(i,1,n)if(du[i]==1)q[++q[0]]=i;
	rep(i,1,q[0]){
		if(i==q[0]){
			assert(i==n);
			printf("! %d\n",q[i]);
			fflush(stdout);
			return 0;
		}
		int x=q[i];
		int y=q[i+1];
		int w=Q(x,y);
		if(w==x||w==y){
			printf("! %d\n",w);
			fflush(stdout);
			return 0;
		}
		for(int d:go[x]){
			du[d]--;if(du[d]==1)q[++q[0]]=d;
		}
		for(int d:go[y]){
			du[d]--;if(du[d]==1)q[++q[0]]=d;
		}
		i++;
	}
	assert(0);
	return 0;
}