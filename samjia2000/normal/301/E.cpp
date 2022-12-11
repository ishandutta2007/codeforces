#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<set>
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

const int M = 105;
const int N = 105;
const int mo = 1e+9+7;

int n,m,k;
int f[M][2][M][N],C[N][N];

int main(){
	n=get();m=get();k=get();
	n/=2;
	fo(i,0,100){
		C[i][0]=1;
		fo(j,1,i)C[i][j]=min(200,(C[i-1][j-1]+C[i-1][j])%mo);
	}
	int ans=0;
	int now=1;
	fo(i,1,n)f[i][1][i][1]=1;
	fo(j,1,min(m-1,n)){
		int t=now^1;
		fo(i,1,n)memset(f[i][t],0,sizeof(f[i][t]));
		fo(i,1,n)
			fo(x,1,i)
				fo(y,1,k)
				if (f[i][now][x][y]){
					ans=(ans+LL(f[i][now][x][y])*(m-j))%mo;
					fo(c,1,n-i)
					if (y*C[c+x-1][x-1]<=k)
					f[i+c][t][c][y*C[c+x-1][x-1]]=(f[i+c][t][c][y*C[c+x-1][x-1]]+f[i][now][x][y])%mo;
				}
		now=t;
	}
	printf("%d\n",ans);
	return 0;
}