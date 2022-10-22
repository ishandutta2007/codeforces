#include<bits/stdc++.h>
using namespace std;
#define mn 605
#define vc vector<double>
#define eps 1e-10
int n,m,k;
int c[mn],V[mn],cnt,id[mn];
int deg[mn],G[mn][mn];
double a[mn][mn];
vc operator+(vc a,const vc &b){//a.size()==b.size()
	for(int i=0;i<a.size();++i)a[i]=a[i]+b[i];
	return a;
}
vc operator-(vc a,const vc &b){
	for(int i=0;i<a.size();++i)a[i]=a[i]-b[i];
	return a;
}
vc operator *(vc a,const double &b){
	for(int i=0;i<a.size();++i)a[i]*=b;
	return a;
}
vc operator /(vc a,const double &b){
	for(int i=0;i<a.size();++i)a[i]/=b;
	return a;
}
vc v[mn];
struct mat{
	double a[105][105];
	void init(){
		for(int i=0;i<=cnt;++i)
			for(int j=0;j<=cnt;++j)
				a[i][j]=0;
	}
}g;
mat operator *(mat a,mat b){
	mat c;c.init();
	for(int i=1;i<=cnt;++i)
		for(int j=1;j<=cnt;++j)
			for(int k=1;k<=cnt;++k)
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]);
	return c;
}
void Gauss(){
	for(int i=1;i<=n+cnt;++i){
		double w=a[i][i];
		assert(fabs(w)>eps);
		for(int j=i;j<=n+cnt;++j){
			a[i][j]/=w;
		}
		v[i]=v[i]/w;
		for(int j=1;j<=n+cnt;++j){
			if(i==j||fabs(a[j][i])<eps)continue;
			double w=a[j][i];
			for(int k=i;k<=n+cnt;++k){
				a[j][k]-=a[i][k]*w;
			}
			v[j]=v[j]-v[i]*w;
		}
	}
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=cnt;++j){
			g.a[i][j]=v[V[i]][j];
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
		if(c[i]){
			V[++cnt]=i;
			id[i]=n+cnt;
		}
		else id[i]=i;
	}
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u]++;deg[v]++;
		G[u][v]++;G[v][u]++;
	}
	for(int i=1;i<=n+cnt;++i)v[i].resize(cnt+1);
	for(int i=1;i<=n;++i){
		a[i][i]=-1;
		double tmp=1.0/deg[i];
		for(int j=1;j<=n;++j){
			a[i][id[j]]+=tmp*G[i][j];
		}
	}
	for(int i=1;i<=cnt;++i){
		a[i+n][i+n]=1;v[i+n][i]=1;
	}
	Gauss();
	k-=2;
	mat F;F.init();
	for(int i=1;i<=cnt;++i){
		F.a[1][i]=v[1][i];
	}
	while(k){
		if(k&1)F=F*g;
		k>>=1;
		g=g*g;
	}
	printf("%.10lf",F.a[1][id[n]-n]);
	return 0;
}


//fk 