#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int mo = 1e9+7;
const int N = 3e3+5;

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

int n,D;
int fa[N],lef[N],rig[N];
LL inv[N],js[N];
LL B[N];
int len;
LL f[N][N];

void dfs(int x){
	if (!lef[x]){
		fo(i,1,len)f[x][i]=i;
		return;
	}
	fo(i,1,len)f[x][i]=1;
	for(int y=lef[x];y;y=rig[y]){
		dfs(y);
		fo(i,1,len)f[x][i]=f[x][i]*f[y][i]%mo;
	}
	fo(i,1,len)f[x][i]=add(f[x][i],f[x][i-1]);
}

LL F[N];
LL G[N],tmp[N];

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if(tim&1)ret=ret*x%mo;
	return ret;
}

int main(){
	n=get();D=get();
	len=n+1;
	inv[0]=inv[1]=1;
	fo(i,2,len)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,1,len)inv[i]=inv[i]*inv[i-1]%mo;
	js[0]=js[1]=1;
	fo(i,2,len)js[i]=js[i-1]*i%mo;
	fo(i,2,n){
		fa[i]=get();
		rig[i]=lef[fa[i]];
		lef[fa[i]]=i;
	}
	dfs(1);
	G[0]=1;
	fo(i,1,len){
		//(x-i)
		fd(x,len,1)G[x]=((-G[x]*i+G[x-1])%mo+mo)%mo;
		G[0]=(mo-G[0]*i%mo)%mo;
	}
	//fo(i,1,n)f[1][i]=add(f[1][i],f[1][i-1]);
	fo(i,1,len){
		LL v=f[1][i];
		v=v*inv[i-1]%mo;
		v=v*inv[len-i]%mo;
		if ((len-i)&1)v=dec(0,v);
		//G/(x-i)
		fo(x,0,len)tmp[x]=0;
		tmp[0]=(mo-G[0]*quickmi(i,mo-2)%mo)%mo;
		LL ny=inv[i]*js[i-1]%mo;
		fo(x,1,len)tmp[x]=(mo-(G[x]-tmp[x-1])*ny%mo)%mo;
		fo(x,0,len)tmp[x]=tmp[x]*v%mo;
		fo(x,0,len)F[x]=add(F[x],tmp[x]);
	}
	LL ans=0,now=1;
	fo(i,0,len){
		ans=add(ans,now*F[i]%mo);
		now=now*D%mo;
	}
	cout<<ans<<endl;
	return 0;
}