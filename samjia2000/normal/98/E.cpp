#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int get(){
	char ch;
	int s=0;
	while(ch=getchar(),ch<'0'||ch>'9');
	s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

typedef double db;

const int N = 1010;

db f[N][N];
int n,m;

int main(){
	n=get();m=get();
	int v=max(n,m);
	fo(i,0,v)f[0][i]=1.0/(i+1);
	fo(i,0,v)f[i][0]=1;
	fo(s,2,v+v)
		fo(j,1,min(v,s-1)){
			int i=s-j;
			if (i>v)continue;
			db k0=db(j)/(j+1)*(1-f[j-1][i]),k1=1.0/(j+1)+db(j)/(j+1)*(1-f[j-1][i]),
			b0=1,b1=1.0-f[j][i-1];
			k0-=b0;k1-=b1;
			db p=(b1-b0)/(k0-k1);
			f[i][j]=k0*p+b0;
		}
	printf("%.16lf %.16lf\n",f[n][m],1.0-f[n][m]);
	return 0;
}