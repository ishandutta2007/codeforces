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

const int N = 1010;

bool bz[N][N];
int a[N],w;

int main(){
	int k=get();
	int n=3;
	bz[1][3]=bz[3][1]=1;
	int len=1;
	while(k){
		a[++w]=k%2;
		k/=2;
	}
	fd(i,w-1,1){
		if (a[i]==0){
			bz[n][n+1]=bz[n+1][n]=bz[n][n+2]=bz[n+2][n]=bz[n+1][n+3]=bz[n+3][n+1]=bz[n+2][n+3]=bz[n+3][n+2]=1;
			len+=2;
			n+=3;
		}
		else{
			bz[1][n+1]=bz[n+1][1]=1;
			fo(k,2,len+1)
			bz[n+k-1][n+k]=bz[n+k][n+k-1]=1;
			int ed=n+len+1;
			bz[n][ed+1]=bz[ed+1][n]=bz[n][ed+2]=bz[ed+2][n]=1;
			fo(k,0,2)
			bz[ed+k][ed+3]=bz[ed+3][ed+k]=1;
			len+=2;
			n=ed+3;
		}
	}
	printf("%d\n",n);
	bz[n][2]=bz[2][n]=1;
	fo(i,1,n){
		fo(j,1,n)
		if (bz[i][j])putchar('Y');else putchar('N');
		putchar('\n');
	}
	return 0;
}