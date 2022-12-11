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

const int N = 410;
const int mo = 1e+9+7;

LL f[N][N];
int n;

LL add(LL x,LL y){
	return x+y>=mo?x+y-mo:x+y;
}

int main(){
	n=get();
	f[1][0]=f[1][1]=1;
	fo(i,2,n){
		fo(l,0,n)fo(r,0,n){
			LL v=f[i-1][l]*f[i-1][r]%mo;
			if (l+r+1<=n)f[i][l+r+1]=add(f[i][l+r+1],v);
			if (l+r<=n)f[i][l+r]=add(f[i][l+r],v*(2*(l+r)+1)%mo);
			if (l+r>=2&&l+r-1<=n)f[i][l+r-1]=add(f[i][l+r-1],v*(l+r)*(l+r-1)%mo);
		}
	}
	printf("%I64d\n",f[n][1]);
	return 0;
}