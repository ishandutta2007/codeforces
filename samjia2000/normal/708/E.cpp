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

const int N = 1505;
const int mo = 1e9+7;

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}
LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

int n,m,k;
LL A,B,p,q;
LL choose[N];
LL f[N][N][2],g[N][N];
LL val[N],pre[N];
LL suf0[N],pre1[N],suf1[N],pv1[N],pv2[N];

int main(){
	n=get();m=get();
	A=get();B=get();
	k=get();
	p=A*quickmi(B,mo-2)%mo;
	q=(mo+1-p)%mo;
	choose[0]=1;
	fo(i,1,m)choose[i]=choose[i-1]*quickmi(i,mo-2)%mo*(k-i+1)%mo;
	fo(i,0,m)val[i]=choose[i]*quickmi(p,i)%mo*quickmi(q,k-i)%mo;
	pre[0]=val[0];
	fo(i,1,m)pre[i]=add(pre[i-1],val[i]);
	if (n==1){
		LL ans=0;
		fo(l,1,m)
			fo(r,l,m)ans=add(ans,val[l-1]*val[m-r]%mo);
		cout<<ans<<endl;
		return 0;
	}
	fo(l,1,m)f[1][l][1]=val[l-1];
	fo(i,1,n-1){
		fd(x,m,1){
			suf0[x]=add(suf0[x+1],f[i][x][0]*pre[m-x]%mo);
			suf1[x]=add(suf1[x+1],f[i][x][1]*pre[m-x]%mo*pre[m-x]%mo);
		}
		fo(x,1,m){
			pre1[x]=add(pre1[x-1],f[i][x][1]);
			pv1[x]=add(pv1[x-1],f[i][x][0]*pre[x-1]%mo);
			pv2[x]=add(pv2[x-1],f[i][x][1]*pre[m-x]%mo*pre[x-1]%mo);
		}
		fo(y,1,m)f[i+1][y][0]=add(f[i+1][y][0],suf0[y]*val[y-1]%mo);
		fo(y,1,m)f[i+1][y][1]=add(f[i+1][y][1],pre1[y-1]*val[y-1]%mo*pre[m-y]%mo);
		fo(y,1,m)f[i+1][y][0]=add(f[i+1][y][0],suf1[y]*val[y-1]%mo);
		if (i+1<n){
			fo(y,2,m)f[i+2][y][1]=add(f[i+2][y][1],suf0[y]*pre[y-2]%mo*val[y-1]%mo);
			fo(y,2,m)f[i+2][y][1]=add(f[i+2][y][1],pv1[y-1]*pre[m-y]%mo*val[y-1]%mo);
			fo(y,2,m)f[i+2][y][1]=add(f[i+2][y][1],suf1[y]*pre[y-2]%mo*val[y-1]%mo);
			fo(y,2,m)f[i+2][y][1]=add(f[i+2][y][1],pv2[y-1]*pre[m-y]%mo*val[y-1]%mo);
		}
	}
	LL ans=0;
	fo(x,1,m){
		ans=add(ans,f[n][x][0]);
		ans=add(ans,f[n][x][1]*pre[m-x]%mo);
	}
	cout<<ans<<endl;
	return 0;
}