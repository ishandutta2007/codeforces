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

const int N = 505;
const int mo = 1e+9+7;

LL f[N][N],g[N][N];
int n;
int a[N][N];

LL quickmi(LL x,LL tim){
	LL ans=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ans=ans*x%mo;
	return ans;
}

int main(){
	n=get();
	fo(i,1,n)
		fo(j,1,n)
		a[i][j]=get();
	fo(i,1,n)g[i][i]=f[i][i]=1;
	fo(l,2,n){
		fo(x,1,n){
			int y=(x+l-2)%n+1;
			for(int z=x;z!=y;z=z==n?1:z+1)
			g[x][y]=(g[x][y]+f[x][z]*f[z==n?1:z+1][y]%mo)%mo;
			for(int z=x;z!=y;z=z==n?1:z+1)
			if (a[y][z])f[x][y]=(f[x][y]+f[x][z]*g[z][y]%mo)%mo;
		
		}
	}
	LL ans=0;
	fo(i,1,n)ans=(ans+f[i][i==1?n:i-1])%mo;
	ans=ans*quickmi(n,mo-2)%mo;
	printf("%I64d\n",ans);
	return 0;
}