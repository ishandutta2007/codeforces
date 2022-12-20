#include<bits/stdc++.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
#define N 5100
using namespace std;
const double pi=acos(-1);
int64 f[2][2*N];
int P[N*2],X[N],Y[N],n,x,tot,t;
int Find(int x){
	return lower_bound(P+1,P+tot+1,x)-P;
}
int main(){
	scanf("%d%d",&n,&x);
	P[tot=1]=x;
	rep(i,1,n)scanf("%d%d",&X[i],&Y[i]),P[++tot]=X[i],P[++tot]=Y[i];
	sort(P+1,P+tot+1);
	x=Find(x);
	memset(f,3,sizeof(f));
	f[0][x]=0;
	t=0;
	rep(i,1,n){
		t^=1;
		rep(j,1,tot)f[t][j]=f[t^1][j];
		rep(j,2,tot)f[t][j]=min(f[t][j],f[t][j-1]+P[j]-P[j-1]);
		for(int j=tot-1;j>=1;--j)f[t][j]=min(f[t][j],f[t][j+1]+P[j+1]-P[j]);
		rep(j,1,tot){
			int z;
			if(P[j]>=X[i] && P[j]<=Y[i])z=0;
			else if(P[j]<X[i])z=X[i]-P[j];
			else z=P[j]-Y[i];
			f[t][j]+=z;
		}
	}
	int64 ans=1ll<<60;
	rep(i,1,tot)ans=min(ans,f[t][i]);
	printf("%I64d\n",ans);
}