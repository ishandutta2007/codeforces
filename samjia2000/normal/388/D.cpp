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

const int mo = 1e+9+7;
const int N = 40;

LL f[N][N][2];
int n;
int a[N],w;

int main(){
	int x=get();
	while(x){
		a[++n]=x%2;
		x/=2;
	}
	f[n][1][1]=1;
	fd(i,n-1,1){
		fo(j,1,n){
			//0
			f[i][j][0]=(f[i][j][0]+f[i+1][j][0]*(1<<(j-1))%mo)%mo;
			if (a[i])f[i][j][0]=(f[i][j][0]+f[i+1][j][1]*(1<<(j-1))%mo)%mo;
			else f[i][j][1]=(f[i][j][1]+f[i+1][j][1]*(1<<(j-1))%mo)%mo;
			//1
			f[i][j][0]=(f[i][j][0]+f[i+1][j][0]*(1<<(j-1))%mo)%mo;
			if (a[i])f[i][j][1]=(f[i][j][1]+f[i+1][j][1]*(1<<(j-1))%mo)%mo;
			//new
			f[i][j+1][0]=(f[i][j+1][0]+f[i+1][j][0])%mo;
			if (a[i])f[i][j+1][1]=(f[i][j+1][1]+f[i+1][j][1])%mo;
		}
		f[i][1][0]=(f[i][1][0]+1)%mo;
	}
	LL ans=1;
	fo(i,1,n)ans=(ans+f[1][i][0]+f[1][i][1])%mo;
	printf("%I64d\n",ans);
	return 0;
}