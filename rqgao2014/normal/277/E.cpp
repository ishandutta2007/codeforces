#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debug puts("isok")
using namespace std;

const double inf=1e9+7,eps=1e-7;
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
int n,m,x[805],y[805],match[805];
double w[805][805],mx[805],my[805],slack[805];
bool vx[805],vy[805];
inline void add(int x,int y,double v){
	w[x][y<<1]=w[x][(y<<1)-1]=-v;
	mx[x]=max(mx[x],-v);
}
inline bool hungary(int x){
	vx[x]=1;
	for(int i=1;i<=m;i++){
		if(w[x][i]<=-inf) continue;
		if(mx[x]+my[i]-w[x][i]>eps){slack[i]=min(slack[i],mx[x]+my[i]-w[x][i]);continue;}
		if(vy[i]) continue;
		vy[i]=1;
		if(!match[i]||hungary(match[i])){
			match[i]=x;return 1;
		}
	}
	return 0;
}
inline double dis(int a,int b){
	return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));
}
inline bool solve(int x){
	for(int i=1;i<=m;i++) slack[i]=inf;
	memset(vx,0,sizeof(vx));
	memset(vy,0,sizeof(vy));
	return hungary(x);
}
void km(){
	m=n<<1;
	for(int i=1;i<=n;i++){
		mx[i]=-inf;
		for(int j=1;j<=m;j++) w[i][j]=-inf;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(y[i]>y[j]) add(j,i,dis(i,j));
	int res=n;
	for(int i=1;i<=n;i++)
		while(!solve(i)){
			double d=inf;
			for(int j=1;j<=m;j++) if(!vy[j])d=min(d,slack[j]);
			if(d>=inf){res--;break;}
			for(int j=1;j<=n;j++) if(vx[j]) mx[j]-=d;
			for(int j=1;j<=m;j++) if(vy[j]) my[j]+=d;
		}
	if(res>=n-1){
		double ans=0.0;
		for(int i=1;i<=m;i++) if(match[i]) ans-=w[match[i]][i];
		printf("%.15f\n",ans);
	}
	else puts("-1");
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	km();
	return 0;
}