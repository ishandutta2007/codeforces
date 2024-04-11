#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e4+5;

int n;
db c,p[N];
db f[2][N],g[2][N],ans[2][N],Ans[2][N];
db js[N];

db choose(int n,int m){return n<m?0:js[n]/js[m]/js[n-m];}

int main(){
	n=get();c=(db)get()/1e6;
	fo(i,0,n){
		p[i]=(db)get()/1e6;
	//	if (p[i]==0)p[i]=1e-9;
	}
	//js[0]=1;fo(i,1,n)js[i]=js[i-1]*i;
	fo(i,0,n-1){
		int j=n-1-i;
		g[0][i]=p[i]*(n-i)/n+p[i+1]*(i+1)/n;
		if (g[0][i]>0)ans[0][i]=max((db)0,-c+p[i+1]*(i+1)/n/g[0][i]);
	}
	int o=0;
	fd(s,n-2,0){
		int t=o^1;
		fo(i,0,s){
			int j=s-i;
			db v0=g[o][i+1]*(i+1)/(s+1),v1=g[o][i]*(j+1)/(s+1);
			g[t][i]=v0+v1;
			ans[t][i]=max((db)0,v0+v1>0?-c+(v0*(ans[o][i+1]+1)+v1*ans[o][i])/(v0+v1):0);
		}
		ans[0][s+1]=ans[1][s+1]=0;
		swap(o,t);
	}
	printf("%.12lf\n",ans[o][0]);
	//printf("%.12lf\n",Ans[0][0]);
	return 0;
}