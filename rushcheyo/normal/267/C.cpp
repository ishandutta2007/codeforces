#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int n,m,u[5005],v[5005],w[5005];
double a[105][105];
void gauss(){
	for(int i=1;i<=n;i++){
		int r=i;
		for(int j=i+1;j<=n;j++)
			if(fabs(a[j][i])>fabs(a[r][i]))r=j;
		if(r!=i)
			for(int j=i;j<=n+1;j++)swap(a[i][j],a[r][j]);
		for(int j=1;j<=n;j++)
			if(j!=i){
				if(fabs(a[i][i])<eps)continue;
				double t=a[j][i]/a[i][i];
				for(int k=i;k<=n+1;k++)
					a[j][k]-=a[i][k]*t;
			}
	}
	for(int i=1;i<=n;i++)
		if(fabs(a[i][i])>eps)a[i][n+1]/=a[i][i];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",u+i,v+i,w+i);
		a[u[i]][u[i]]++,a[u[i]][v[i]]--;
		a[v[i]][v[i]]++,a[v[i]][u[i]]--;
	}
	for(int i=1;i<=n;i++)a[1][i]=a[n][i]=0;
	a[1][1]=a[n][n]=1;
	a[1][n+1]=1,a[n][n+1]=0;
	gauss();
	double ans=0,t=1e20;
	for(int i=1;i<=m;i++){
		double I=a[u[i]][n+1]-a[v[i]][n+1];
		if(fabs(I)>=eps)t=min(t,w[i]/fabs(I));
		if(u[i]==1)ans+=I;
		if(v[i]==1)ans-=I;
	}
	printf("%.10f\n",ans*t);
	for(int i=1;i<=m;i++)
		printf("%.10f\n",(a[u[i]][n+1]-a[v[i]][n+1])*t);
}