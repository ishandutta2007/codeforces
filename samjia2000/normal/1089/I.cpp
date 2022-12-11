#include<bits/stdc++.h>

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

const int N = 405;
const int L = 400;

int mo;
LL f[N],g[N][N],s[N];
LL js[N],inv[N];
LL h[N];

int main(){
	int T=get();
	mo=get();
	js[0]=js[1]=1;
	fo(i,2,L)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,L)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,L)inv[i]=inv[i]*inv[i-1]%mo;
	g[0][0]=1;
	fo(i,0,L-1)
		fo(x,0,L)
		if (g[i][x])
			fo(y,1,L-x)g[i+1][x+y]=(g[i+1][x+y]+g[i][x]*js[y])%mo;
	h[2]=1;
	fo(i,1,L){
		f[i]=js[i];
		fo(j,2,i-1)f[i]=(f[i]+mo-f[j]*(g[j-1][i-1])%mo)%mo;
		s[i]=f[i];
		fo(j,3,i-1)s[i]=(s[i]+mo-s[j]*f[i-j+1]%mo)%mo;
		if (i>2){
			h[i]=(f[i-1]+mo-h[i-1])%mo;
			s[i]=(s[i]+mo-h[i]*2%mo)%mo;
		}
	}
	for(;T;T--){
		int n=get();
		cout<<s[n]<<endl;
	}
	return 0;
}