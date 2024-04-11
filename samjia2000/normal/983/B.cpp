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

const int N = 5005;

int n;
int a[N];
int q;
int f[N][N];

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)f[i][i]=a[i];
	fo(len,1,n-1)
		fo(i,1,n-len){
			int d=len&-len;
			f[i][i+len]=f[i][i+len-1]^f[i+1][i+len];
		}
	fd(i,n,1)
		fo(j,1,n){
			f[i-1][j]=max(f[i-1][j],f[i][j]);
			f[i][j+1]=max(f[i][j+1],f[i][j]);
		}
	q=get();
	fo(i,1,q){
		int l=get(),r=get();
		printf("%d\n",f[l][r]);
	}
	return 0;
}