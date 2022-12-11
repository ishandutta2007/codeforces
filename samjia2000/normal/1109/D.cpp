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

const int N = 2e6+5;
const int mo = 1e9+7;

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
		if (tim&1)ret=ret*x%mo;
	return ret;
}
LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

int n,m;
LL js[N],inv[N];
LL f[N],g[N];

LL calc(int n,int m){return (n<m||m<0)?0:js[n]*inv[m]%mo*inv[n-m]%mo;}

int main(){
	n=get();m=get();
	js[0]=js[1]=1;
	fo(i,2,n+m)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,n+m)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,n+m)inv[i]=inv[i]*inv[i-1]%mo;
	LL ans=0;
	fo(i,1,n-1){
		f[i]=calc(n-2,i-1)*js[i-1]%mo;
		//n-i
		if (i<n-1)f[i]=f[i]*quickmi(n,n-i-2)%mo*(i+1)%mo;
		g[i]=f[i]*calc(m-1,i-1)%mo*quickmi(m,n-1-i)%mo;
		ans=add(ans,g[i]);
	}
	cout<<ans<<endl;
	return 0;
}