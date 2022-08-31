#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
int p[47777][9];
int val[47777];
int n;int m;
int main(){
	scanf("%d%d",&n,&m);
	
	int cnt=1;
	rep(i,1,n)cnt*=i;
	
	int ma=0;
	rep(i,1,n)p[1][i]=i;
	rep(i,1,cnt){
		if(i!=1){
		rep(j,1,n)p[i][j]=p[i-1][j];
		next_permutation(p[i]+1,p[i]+1+n);}
		int pa=0;
		rep(j,1,n)rep(k,j,n){
			pa=23333;
			rep(u,j,k)if(p[i][u]<pa)pa=p[i][u];
			val[i]+=pa;
		}
		if(val[i]>ma)ma=val[i];
	}
	rep(i,1,cnt)if(val[i]==ma){
		m--;
		if(!m){
			rep(j,1,n)printf("%d ",p[i][j]);
			return 0;
		}
	}
	return 0;
}