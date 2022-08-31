#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1005,MOD=998244353;
int pw(int x,int y){
	int s=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)s=1ll*s*x%MOD;
	return s;
}
int a[N][N],s[N][N],n,m,r,c;
int Q[N*N],q[N*N];
bool cmp(int A,int B){
	return Q[A]<Q[B];
}
int T,A,B,sig;
int main(){
	scanf("%d%d",&n,&m);
	int top=0;
	rep(i,n)rep(j,m)scanf("%d",a[i]+j),Q[++top]=a[i][j];
	scanf("%d%d",&r,&c);
	//r=c=1000;
	rep(i,n*m)q[i]=i;
	sort(q+1,q+n*m+1,cmp);
	int j;
	for(int i=1;i<=n*m;i=j){
		for(j=i;j<=n*m&&Q[q[i]]==Q[q[j]];++j){
			int x=(q[j]-1)/m+1,y=(q[j]-1)%m+1,ans=0;
			ans=(T+1ll*A*x%MOD+1ll*B*y%MOD+1ll*(x*x+y*y)*(i-1)%MOD+sig)%MOD;
			ans=1ll*ans*pw(i-1,MOD-2)%MOD;
			s[x][y]=ans;
			//printf("%d %d %d\n",x,y,ans);
			if(x==r&&y==c){printf("%d\n",ans);return 0;}
		}
		for(j=i;j<=n*m&&Q[q[i]]==Q[q[j]];++j){
			int x=(q[j]-1)/m+1,y=(q[j]-1)%m+1,ans=s[x][y];
			T=(T+1ll*(x*x+y*y))%MOD;
			A=(A-2ll*x%MOD+MOD)%MOD;
			B=(B-2ll*y%MOD+MOD)%MOD;
			sig=(sig+ans)%MOD;
		}
	}
	return 0;
}