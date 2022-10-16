#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN=106;
const int MAXP=55;
const int MAXM=200010;
const int INF=0x3fffffff;
const double Pi=acos(-1);
struct Edge{
	int u,v,c;
}edge[MAXN];
struct cpx{
	double r,i;
	cpx(){}
	cpx(double r1,double i1):r(r1),i(i1){}
	cpx operator +(const cpx &a)const{
		return cpx(r+a.r,i+a.i);	
	}
	cpx operator -(const cpx &a)const{
		return cpx(r-a.r,i-a.i);	
	}
	cpx operator *(const cpx &a)const{
		return cpx(r*a.r-i*a.i,r*a.i+i*a.r);
	}
}A[MAXM],B[MAXM];
double p[MAXN][MAXM],f[MAXP][MAXM],S[MAXN][MAXM];
int dist[MAXN][MAXN];
int n,m,t,x;
void FFT(cpx a[],int N,int flag){
	int i,j,k;
	for(i=1,j=0;i<N;i++){
		for(int d=N;j^=d>>=1,~j&d;);
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	for(i=1;i<N;i<<=1){
		cpx wn=cpx(cos(Pi/i),flag*sin(Pi/i));
		for(j=0;j<N;j+=(i<<1)){
			cpx w=cpx(1,0);
			for(k=0;k<i;k++,w=w*wn){
				cpx X=a[j+k],Y=w*a[i+j+k];
				a[j+k]=X+Y;
				a[i+j+k]=X-Y;	
			}
		}
	}
	if(flag==-1){
		for(int i=0;i<N;i++){
			a[i].r/=N;
		}
	}
}
void cal(int l,int r,int mid){
	int len=r-l;
	for(int j=1;j<=m;j++){
		int v=edge[j].v;
		int N=1;
		while(N<len+r-mid+1){
			N<<=1;
		}
		for(int i=0;i<N;i++){
			A[i]=B[i]=cpx(0,0);
		}
		for(int i=0;i<=r-mid;i++){
			A[i]=cpx(f[v][r-i],0);
		}
		for(int i=0;i<len;i++){
			B[i]=cpx(p[j][i+1],0);
		}
		FFT(A,N,1);
		FFT(B,N,1);
		for(int i=0;i<N;i++){
			A[i]=A[i]*B[i];
		}
		FFT(A,N,-1);
		for(int i=l;i<mid;i++){
			S[j][i]+=A[r-i-1].r;
		}
	}
}
void CDQ(int l,int r){
	if(l==r){
		for(int i=1;i<=m;i++){
			int u=edge[i].u;
			f[u][l]=min(f[u][l],S[i][l]+edge[i].c);
		}
		return ;
	}	
	int mid=(l+r)>>1;
	CDQ(mid+1,r);
	cal(l,r,mid+1);
	CDQ(l,mid);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&t,&x);
	int u,v,len;
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++)
		dist[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&len);	
		edge[i].u=u;
		edge[i].v=v;
		edge[i].c=len;
		dist[u][v]=min(dist[u][v],len);
		for(int j=1;j<=t;j++){
			scanf("%lf",&p[i][j]);
			p[i][j]/=100000.0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
			}
		}
	}
	for(int i=0;i<=t;i++){
		f[n][i]=0;
	}
	for(int i=t+1;i<=2*t;i++){
		f[n][i]=x;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=2*t;j++){
			if(j>t){
				f[i][j]=dist[i][n]+x;
			}
			else{
				f[i][j]=INF;
			}
		}
	}
	cal(1,t*2,t+1);
	CDQ(0,t);
	printf("%lf\n",f[1][0]);
}