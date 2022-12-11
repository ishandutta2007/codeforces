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

const int mo = 998244353;
const int N = 1e6+5;

int n;
LL js[N],inv[N];

LL calc(int n,int m){return js[n]*inv[m]%mo*inv[n-m]%mo;}

LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

int main(){
	n=get();
	js[0]=1;
	fo(i,1,n)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,n)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,n)inv[i]=inv[i-1]*inv[i]%mo;
	LL ans=1;
	fo(i,1,n-1){
		LL a=calc(n,n-i)*i%mo,b=calc(n,n-i+1);
		a=dec(a,b)*js[i-1]%mo;
		ans=(ans+a*i)%mo;
	}
	cout<<ans<<endl;
	return 0;
}