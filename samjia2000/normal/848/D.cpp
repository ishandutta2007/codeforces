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
const int N = 55;

LL f[N][N],g[N][N],tp[N][N];
int n,m;
LL ny[N];

LL quickmi(LL x,LL tim){
	LL ans=1;
	x=x%mo;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ans=ans*x%mo;
	return ans;
}

LL multi(LL x,int t){
	x=(x+t-1)%mo;
	LL ans=1;
	fo(i,1,t)ans=ans*(x-t+i+mo)%mo*ny[i]%mo;
	return ans;
}

void add(LL &x,LL v){
	x=x+v>=mo?x+v-mo:x+v;
}

int main(){
	n=get();m=get();
	f[0][1]=1;
	ny[0]=1;
	fo(i,1,50)ny[i]=quickmi(i,mo-2);
	fo(s,1,n){
		fo(a,0,s-1)
			fo(b,0,a+1){
				int c=s-1-a;
				fo(d,0,c+1)
				add(g[s][min(b,d)],f[a][b]*f[c][d]%mo);
			}
		fo(j,0,s+1)
			fd(p,n,0)
				fd(t,p+1,0)
					for(int q=1;p+s*q<=n;q++)
					add(f[p+s*q][t+j*q],f[p][t]*multi(g[s][j],q)%mo);
	}
	printf("%I64d\n",f[n][m]);
	return 0;
}