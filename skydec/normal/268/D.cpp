#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
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
#define jsb 1000000009
int f[32][32][32][2],g[32][32][32][2];
int n,h;int aft[32];bool cao[32];int pq[3];
inline void ADD(int &x,int y){x+=y;if(x>=jsb)x-=jsb;}
inline int A(int a,int b,int c,int wei,int res){
	int q[4];q[1]=a;q[2]=b;q[3]=c;sort(q+1,q+1+3);
	ADD(g[q[1]][q[2]][q[3]][wei],res);
}
int main(){
	scanf("%d%d",&n,&h);rep(i,0,h-1)aft[i]=i+1;aft[h]=h;
	rep(i,0,h-1)cao[i]=1;cao[h]=0;pq[1]=1;pq[0]=h;
	f[1][1][1][1]=4;
	rep(i,1,n-1){
		rep(j,1,h)
		rep(k,j,h)
		rep(l,k,h)
		rep(wei,0,1)
		{
			int res=f[j][k][l][wei];
			A(aft[j],aft[k],aft[l],wei,res);
			A(pq[wei],aft[j],aft[k],cao[l],res);
			A(pq[wei],aft[j],aft[l],cao[k],res);
			A(pq[wei],aft[l],aft[k],cao[j],res);
		}
		rep(j,1,h)rep(k,j,h)rep(l,k,h)rep(wei,0,1){
			//printf("for %d:f[%d][%d][%d][%d]=%d\n",i,j,k,l,wei,f[j][k][l][wei]);
			f[j][k][l][wei]=g[j][k][l][wei];
			g[j][k][l][wei]=0;
		}
	}
	int res=0;
	rep(j,1,h)rep(k,j,h)rep(l,k,h)rep(wei,0,1)
	if(wei||(j<h)||(k<h)||(l<h))ADD(res,f[j][k][l][wei]);
	printf("%d\n",res);
	return 0;
}