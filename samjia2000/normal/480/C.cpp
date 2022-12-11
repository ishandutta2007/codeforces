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

const int N = 5010;
const int mo = 1e+9+7;

int f[N][N];
int n,a,b,k;
int v[N];

int add(int x,int y){
	return x+y>=mo?x+y-mo:x+y;
}

int main(){
	n=get();a=get();b=get();k=get();
	fo(i,1,n)f[0][i]=1;
	fo(i,1,k){
		fo(j,1,n)v[j]=add(v[j-1],f[i-1][j]);
		fo(j,1,n){
			int t=abs(j-b);
			f[i][j]=((v[min(n,j+t-1)]+mo-v[max(0,j-t)])%mo+mo-f[i-1][j])%mo;
		}
	}
	printf("%d\n",f[k][a]);
	return 0;
}