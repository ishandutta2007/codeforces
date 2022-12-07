#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;

int n,x[3000333],y[3000333],u[3000222],U[3000333];
double ans;
long long A,B,C,d1,d2;

bool pt(int xx,int yy,int q){
	A=y[q+1]-y[q];
	B=x[q]-x[q+1];
	C=-x[q]*A-y[q]*B;
	if (A*xx+B*yy+C==0)return 1;
	int g;
	for (int i=0;i<n;i++)if (A*x[i]+B*y[i]+C!=0){
		g=i;
		break;
	}
	d1=A*xx+B*yy+C;
	d2=A*x[g]+B*y[g]+C;
	d1/=abs(d1);
	d2/=abs(d2);
	return d1==d2;
}

void solve(){
	int mi=1e9;
	for (int i=0;i<n;i++)if (x[i]<mi)mi=x[i];
	for (int i=0;i<=n;i++)x[i]-=mi;
	for (int i=0;i<=2000111;i++)u[i]=1e9,U[i]=-1e9;
	int o;
	long long sq=0;
	for (int i=1;i<=n;i++)sq+=(x[i]-x[i-1])*1ll*(y[i]+y[i-1]);;
	if (sq>0)o=0;else o=1;
	for (int i=0;i<n;i++){
		if (x[i]==x[i+1]){
			u[x[i]]=min(u[x[i]],y[i]);
			U[x[i]]=max(U[x[i]],y[i]);
			u[x[i]]=min(u[x[i]],y[i+1]);
			U[x[i]]=max(U[x[i]],y[i+1]);
			continue;
		}
		int yy=y[i];
		int s=1;
		if (x[i+1]<x[i])s=-1;
		for(int j=x[i];;){
			if ((x[i]<x[i+1])^o){
				while (pt(j,yy+1,i))yy++;
				while (!pt(j,yy,i))yy--;
				U[j]=max(U[j],yy);
			}
			if ((x[i]>x[i+1])^o){
				while (pt(j,yy-1,i))yy--;
				while (!pt(j,yy,i))yy++;
				u[j]=min(u[j],yy);
			}
			if (j==x[i+1])break;
			j+=s;
		}                  
	}
	for (int i=0;i<=2000111;i++)if (u[i]<=U[i])u[i]=U[i]-u[i]+1;else u[i]=0;
	long long s=0;
	double q=0,w=0,e=0;
	for (int i=0;i<=2000111;i++)s+=u[i];
	for (int i=0;i<=2000111;i++){
		e+=w;
		q+=e;
		ans+=(u[i]/1./(s-1))*q;
		e+=-u[i]/1./s;
		w+=u[i]/1./s*2;
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
	x[n]=x[0];
	y[n]=y[0];
	solve();
	for (int i=0;i<=n;i++)swap(x[i],y[i]);
	solve();		
	printf("%.10lf\n",ans);
	return 0;
}