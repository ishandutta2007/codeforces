#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define mn 105
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
#define Mod 1000000007
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
struct mat{
	int a[mn][mn];
}g;
int n,k,a[mn],tot,cnt,f[mn],tmp[mn];
mat operator *(mat a,mat b){
	mat c;
	for(int i=0;i<=tot;++i)
		for(int j=0;j<=tot;++j)
			c.a[i][j]=0;
	for(int i=0;i<=tot;++i)
		for(int k=0;k<=tot;++k)
			for(int j=0;j<=tot;++j){
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%Mod;
			}
	return c;
}
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();tot+=a[i];
	}
	for(int i=n-tot+1;i<=n;++i)cnt+=a[i];
	f[cnt]=1;
	int all=ksm(n*(n-1)/2,Mod-2);
	for(int i=0;i<=tot;++i){
		int A=n-tot-(tot-i),B=tot-i,C=tot-i,D=i;//0/1 in left,0/1 in right
		if(A<0||B<0||C<0||D<0)continue;
		if(D>0){
			g.a[i][i-1]=A*D;
		}
		g.a[i][i]=(n-tot)*(n-tot-1)/2+tot*(tot-1)/2+A*C+B*D;
		g.a[i][i+1]=B*C;
	}
	int K=k;
	while(k){
		if(k&1){
			for(int j=0;j<=tot;++j)tmp[j]=f[j],f[j]=0;
			for(int j=0;j<=tot;++j)
				for(int k=0;k<=tot;++k){
					f[k]=(f[k]+tmp[j]*g.a[j][k])%Mod;
				}
		}
		g=g*g;
		k>>=1;
	}
	printf("%lld\n",f[tot]*ksm(ksm(n*(n-1)/2,K),Mod-2)%Mod);
	return 0;
}