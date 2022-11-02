#include <bits/stdc++.h>

template<typename T>inline void read(T&x){
	register char c; while(!isdigit(c=getchar()));
	for(x=c-48;isdigit(c=getchar());x=x*10+c-48);
}

const int max_N = 17;

const int max_S = 1<<max_N;

const int mod = 1e9 + 7;

//#define INV (5e8+4)

inline int qpow(int x,int k){
	if(k<0)k+=mod-1;
	int res=1;
	for(;k;x=1ll*x*x%mod,k>>=1)
		if(k&1)res=1ll*res*x%mod;
	return res;
}

#define dyx (1<<(i-1))

inline void AND(int*a,int n,int t){
	int len=-1,i,j,k,x,y;
	for(i=n;i;++len,i>>=1);
	for(i=1;i<=len;++i)
		for(j=0;j<n;j+=(1<<i))
			for(k=j;k<j+dyx;++k){
				x=a[k],y=a[k+dyx];
				a[k]=(x+1ll*t*y+mod)%mod;
			}
}

inline void XOR(int*a,int n,int t){
	int len=-1,i,j,k,x,y;
	for(i=n;i;++len,i>>=1);
	for(i=1;i<=len;++i)
		for(j=0;j<n;j+=(1<<i))
			for(k=j;k<j+dyx;++k){
				x=a[k],y=a[k+dyx];
				a[k]=(x+y)%mod;
				a[k+dyx]=(x-y+mod)%mod;
			}
	if(t!=1){
		int inv=qpow(n,-1);
		for(i=0;i<n;++i)a[i]=1ll*a[i]*inv%mod;
	}
}

int n,s[max_S];

int a[max_S],b[max_S];

int f[max_S],ans[max_S];

int tmp[max_N<<1];

inline void solve_XOR(){
	XOR(s,max_S,1);
	for(int i=0;i<max_S;++i){
		b[i]=1ll*s[i]*s[i]%mod;
	}
	XOR(s,max_S,-1),XOR(b,max_S,-1);
}

inline void solve_AND(){
	AND(a,max_S,1),AND(b,max_S,1),AND(s,max_S,1);
	for(int i=0;i<max_S;++i){
		ans[i]=1ll*a[i]*b[i]%mod*s[i]%mod;
	}
	AND(ans,max_S,-1);
}

int main(){
	read(n);
	for(int i=0,x;i<n;++i){
		read(x);
		++s[x];
	}
	a[0]=1ll*s[0]*s[0]%mod;
	for(int i=1;i<max_S;++i){
		int tot=0;
		for(int j=0;j<max_N;++j)
			if((i>>j)&1)tmp[tot++]=1<<j;
		for(int j=0;j<(1<<(tot-1));++j){
			int set=0;
			for(int k=0;k<tot;++k)
				if((j>>k)&1)set|=tmp[k];
			a[i]=(a[i]+2ll*s[set]*s[set^i])%mod;
		}
	}
	solve_XOR();
	f[0]=0,f[1]=1;
	for(int i=2;i<max_S;++i){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	for(int i=0;i<max_S;++i){
		a[i]=1ll*a[i]*f[i]%mod;
		b[i]=1ll*b[i]*f[i]%mod;
		s[i]=1ll*s[i]*f[i]%mod;
	}
	solve_AND();
	int res=0;
	for(int i=0;i<max_N;++i){
		res=(res+ans[1<<i])%mod;
	}
	printf("%d\n",res);
	return 0;
}