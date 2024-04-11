#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

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

const int N = 2010;
const int mo = 998244353;

int n,m,a[N],b[N];
int f1[N][N][11],f2[N][N][11];

void add(int &x,int v){
	x=x+v>=mo?x+v-mo:x+v;
}

int main(){
	for(int T=get();T;T--){
		int tt=get();
		n=m=0;
		fo(i,1,tt){
			int x=get();
			int len=0,v=x;
			for(;v;len++,v/=10);
			if (len&1)a[++n]=x%11;
			else b[++m]=x%11;
		}
		f1[0][0][0]=1;
		fo(i,1,n)
			fo(j,0,n/2)
				fo(x,0,10)
				if (f1[i-1][j][x]){
					add(f1[i][j][(x+a[i])%11],f1[i-1][j][x]);
					add(f1[i][j+1][(x+a[i]*10)%11],f1[i-1][j][x]);
				}
		fo(x,0,10)f2[0][(n+1)/2][x]=f1[n][n/2][x];
		fo(i,1,m)
			fo(j,(n+1)/2,(n+1)/2+i-1)
				fo(x,0,10)
				if (f2[i-1][j][x]){
					add(f2[i][j][(x+b[i])%11],1ll*f2[i-1][j][x]*(n+i-j)%mo);
					add(f2[i][j+1][(x+b[i]*10)%11],1ll*f2[i-1][j][x]*j%mo);
				}
		LL ans=0;
		fo(i,(n+1)/2,(n+1)/2+m)ans=(ans+f2[m][i][0])%mo;
		fo(i,1,n/2)ans=ans*i%mo;
		fo(i,1,n-n/2)ans=ans*i%mo;
		fo(i,0,n)fo(j,0,n)fo(x,0,10)f1[i][j][x]=0;
		fo(i,0,m)fo(j,0,n+m)fo(x,0,10)f2[i][j][x]=0;
		printf("%I64d\n",ans);
	}
	return 0;
}