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
const int N=100005;
LL a[N];
int n;
vector<int> gt[61];
int m;
LL b[130];
int f[130][130];
int ck(){
	rep(i,1,m)rep(j,1,m)f[i][j]=(i!=j)*(1e8);
	rep(i,1,m)rep(j,1,m)if(i!=j)if(b[i]&b[j])f[i][j]=1;
	int ans=1e9;
	rep(k,1,m){
		rep(i,1,m)rep(j,1,m)if(i!=k&&j!=k)if(b[i]&b[k])if(b[j]&b[k])if(i!=j)ans=min(ans,2+f[i][j]);
		rep(i,1,m)rep(j,1,m)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	if(ans>n)return -1;
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,0,60)rep(j,1,n)if(a[j]&(1ll<<i))gt[i].pb(j);
	rep(i,0,60)if(gt[i].size()>2){
		printf("3\n");
		return 0;
	}
	rep(i,1,n)if(a[i]>0)b[++m]=a[i];
	printf("%d\n",ck());
	return 0;
}