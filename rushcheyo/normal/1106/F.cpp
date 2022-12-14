#include<bits/stdc++.h>
using namespace std;

const int P=998244353;

int power(int a,int x,int P){
	int ans=1;
	for(;x;x>>=1,a=1ll*a*a%P)
		if(x&1)ans=1ll*ans*a%P;
	return ans;
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int phi(int x){
	int res=x;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			res=res/i*(i-1);
			while(x%i==0)x/=i;
		}
	if(x>1)res=res/x*(x-1);
	return res;
}

int K,b[105],n,m;
struct mat{
	int m[105][105];
}a,res;
mat operator*(const mat&a,const mat&b){
	mat c;
	for(int i=1;i<=K;i++)
		for(int j=1;j<=K;j++)
			c.m[i][j]=0;
	for(int k=1;k<=K;k++)
		for(int i=1;i<=K;i++)
			if(a.m[i][k])
				for(int j=1;j<=K;j++)
					c.m[i][j]=(c.m[i][j]+1ll*a.m[i][k]*b.m[k][j])%(P-1);
	return c;
}

// log_a^b
int flog(int a,int b){
	int m=(int)(sqrt(P)+0.5);
	map<int,int> ma;
	int e=1;
	for(int i=0;i<m;i++){
		ma[e]=i;
		e=1ll*e*a%P;
	}
	e=power(e,P-2,P);
	for(int i=0;i<m;i++){
		if(ma.count(b))return ma[b]+i*m;
		b=1ll*b*e%P;
	}
	return -1;
}

int main(){
	scanf("%d",&K);
	for(int i=1;i<=K;i++)scanf("%d",b+i),res.m[i][i]=1,a.m[i+1][i]=1,a.m[K+1-i][K]=b[i]%(P-1);
	scanf("%d%d",&n,&m);
	for(int e=n-K;e;e>>=1,a=a*a)if(e&1)res=res*a;
	int tmp=res.m[K][K];
	int mm=flog(3,m),g=gcd(tmp,P-1);
	if(mm%g)puts("-1");
	else{
		mm/=g,tmp/=g;int p=(P-1)/g;
		int x=1ll*mm*power(tmp,phi(p)-1,p)%p;
		x=power(3,x,P);
		printf("%d\n",x);
	}
	return 0;
}