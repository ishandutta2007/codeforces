#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,p;
double c1[55][55],c2[55][55],f[55][55];
struct matrix{
	double a[55][55];
	matrix(){
		memset(a,0,sizeof(a));
	}
}A,B;
matrix operator *(matrix a,matrix b){
	matrix ret;
	for(int i=0;i<=50;++i){
		for(int j=0;j<=50;++j){
			for(int k=0;k<=50;++k) ret.a[i][k]+=a.a[i][j]*b.a[j][k];
		}
	}
	return ret;
}
matrix qpow(matrix x,int k){
	matrix res;for(int i=0;i<=50;++i) res.a[i][i]=1;
	while(k){
		if(k&1) res=res*x;x=x*x;k>>=1;
	}
	return res;
}
int main(){
	n=read(),p=read();
	c1[1][1]=p/1e9;c1[1][2]=(1e9-p)/1e9;
	c2[1][2]=(1e9-p)/1e9;
	for(int i=2;i<=50;++i){
		c1[i][1]=p/1e9,c1[i][2]=(1e9-p)/1e9;c2[i][2]=(1e9-p)/1e9;
		// printf("%.5lf\n",p/1e9);
		for(int j=2;j<=50;++j){
			c1[i][j]+=c1[i-1][j-1]*c1[i][j-1];
			c2[i][j]+=c1[i-1][j-1]*c2[i][j-1];
		}
	}
	for(int i=50;i>=1;--i){
		for(int j=50;j>=1;--j){
			c1[i][j]*=(1-c1[i-1][j]);
			c2[i][j]*=(1-c1[i-1][j]);
		}
	}
	f[1][1]=1,f[1][2]=2;
	for(int i=2;i<=50;++i){
		f[i][1]=1;
		double up=0,dw=0;
		for(int j=2;j<=50;++j){
			dw+=c2[i-1][j];up+=f[i-1][j]*c2[i-1][j];
		}
		// printf("i:%d,%.5lf %.5lf\n",i,up,dw);
		f[i][1]+=up/dw;
		for(int j=2;j<=50;++j){
			up=dw=0;
			for(int k=1;k<j;++k){
				up+=c1[i-1][k]*f[i-1][k];dw+=c1[i-1][k];
			}
			f[i][j]=j+up/dw;
		}
	}
	if(n<=50){
		double ans=0;
		for(int i=1;i<=50;++i) ans+=f[n][i]*c1[n][i];printf("%.6lf\n",ans);
	}
	else{
		A.a[0][0]=1;
		for(int i=1;i<=50;++i) A.a[0][i]=f[50][i];
		for(int i=2;i<=50;++i){
			double su=0;
			for(int j=1;j<i;++j) B.a[j][i]+=c1[50][j],su+=c1[50][j];
			// printf("i:%d,%.5lf\n",i,su);
			for(int j=1;j<i;++j) B.a[j][i]/=su;
			B.a[0][i]=i;
		}
		B.a[0][1]=1;B.a[0][0]=1;
		{
			double su=0;
			for(int j=2;j<=50;++j) su+=c2[50][j],B.a[j][1]+=c2[50][j];
			for(int j=2;j<=50;++j) B.a[j][1]/=su;
		}
		// for(int i=0;i<=50;++i) printf("%.5lf ",A.a[0][i]);printf("\n");
		// for(int i=0;i<=50;++i) {
		// 	for(int j=0;j<=50;++j) printf("%.5lf ",B.a[i][j]);printf("\n");
		// }
		A=A*qpow(B,n-50);
		// for(int i=0;i<=50;++i) printf("%.5lf ",A.a[0][i]);printf("\n");
		double ans=0.0;
		for(int i=1;i<=50;++i) ans+=c1[50][i]*A.a[0][i];
		printf("%.5lf\n",ans);
	}
}