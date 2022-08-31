#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<bitset>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 110000
#define BB bitset<MAXN>
vector<BB> g;vector<int> f;BB A;
int n;LL a[MAXN];int import[66];int cnt[66];
int ans[MAXN];
void gause(BB A,int B){
	int m=f.size();
	rep(i,0,m-1)if(A[import[i]]){A^=g[i];B^=f[i];}
	int index=-1;
	rep(i,1,n)if(A[i]){index=i;break;}
	if(index==-1)return;
	import[m]=index;
	
	rep(i,0,m-1)if(g[i][index]){
		g[i]^=A;f[i]^=B;
	}
	g.pb(A);f.pb(B);
}
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%I64d",&a[i]);
	rep(i,1,n)rep(j,0,61)cnt[j]+=((a[i]>>j)&1);
	per(j,61,0)if(cnt[j]&&(!(cnt[j]&1))){
		A.reset();
		rep(i,1,n)A[i]=((a[i]>>j)&1);
		gause(A,1);
	}
	per(j,61,0)if(cnt[j]&&((cnt[j]&1))){
		A.reset();
		rep(i,1,n)A[i]=((a[i]>>j)&1);
		gause(A,0);
	}
	for(int i=0;i<f.size();i++)ans[import[i]]=f[i];
	rep(i,1,n)printf("%d ",2-ans[i]);
	return 0;
}