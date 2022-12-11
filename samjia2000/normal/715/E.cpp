/*
Author : samjia2000
Source : CF715E
*/
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

const int N =255;
const int mo = 998244353;

int n;
int a[N],b[N];
int vis[N],tim;
int to[N][2],p[N],q[N];
bool cir[N];
bool bz[N][2];
LL js[N],inv[N];
LL f[N][N];
LL F[N],G[N];

LL calc(int n,int m){return js[n]*inv[m]%mo*inv[n-m]%mo;}

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

int main(){
	n=get();
	js[0]=1;
	fo(i,1,n)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,n)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,n)inv[i]=inv[i]*inv[i-1]%mo;
	fo(i,1,n)a[i]=get();
	fo(i,1,n)b[i]=get();
	fo(i,1,n){
		if (a[i])to[a[i]][0]=b[i];
		if (b[i])to[b[i]][1]=a[i];
		bz[a[i]][0]=1;bz[b[i]][1]=1;
		if (a[i]&&b[i])p[a[i]]=b[i];
	}
	bz[0][0]=bz[0][1]=0;
	int cnt=0,A=0,B=0,C=0;
	fo(i,1,n)
	if (p[i]&&!vis[i]){
		tim++;
		int x;
		for(x=i;x&&!vis[x];x=p[x])vis[x]=tim;
		if (vis[x]==tim){
			for(x=i;x&&!cir[x];x=p[x])cir[x]=1;
			cnt++;
		}
	}
	fo(i,1,n)q[b[i]]=a[i];
	fo(i,1,n){
		int x;
		if (a[i]&&!b[i]){
			for(x=a[i];q[x];x=q[x]);
			if (!bz[x][1])A++;
		}
		if (!a[i]&&b[i]){
			for(x=b[i];p[x];x=p[x]);
			if (bz[x][0])C++;
			else B++;
		}
		if (!a[i]&&!b[i])C++;
	}
	f[0][0]=1;
	fo(j,1,n){
		LL sum=0;
		fo(i,0,n){
			if (i)f[i][j]=sum*js[i-1]%mo;
			sum=add(sum,f[i][j-1]*inv[i]%mo);
		}
	}
	fo(x,0,min(A,B)){
		LL tmp=calc(A,x)*calc(B,x)%mo*js[x]%mo;
		if (x&1)
			fo(i,0,n)F[i]=dec(F[i],tmp*f[A+B+C-x][i]%mo);
		else
			fo(i,0,n)F[i]=add(F[i],tmp*f[A+B+C-x][i]%mo);
	}
	fo(i,0,n)F[i]=F[i]*js[C]%mo;
	fd(i,n,cnt)F[i]=F[i-cnt];
	fo(i,0,cnt-1)F[i]=0;
	fd(i,n,1)printf("%I64d ",F[i]);
	putchar('\n');
	return 0;
}