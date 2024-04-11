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

const int N = 200005;
const int mo = 1e9+7;

int n,k;
int a[N];
LL js[N],inv[N];

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

LL calc(int n,int m){return js[n]*inv[m]%mo*inv[n-m]%mo;}

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

int main(){
	//freopen("data.in","r",stdin);
	n=get();k=get();
	fo(i,1,n)a[i]=get();
	js[0]=js[1]=1;
	inv[0]=inv[1]=1;
	fo(i,2,n)js[i]=js[i-1]*i%mo;
	fo(i,2,n)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,n)inv[i]=inv[i-1]*inv[i]%mo;
	//f[n,i]=i^n
	//f[n,i]/i!=sigma(g[n,j]/(i-j)!,j<=i)
	//g[n,i]=sigma((-1)^j*(i-j)^n/(i-j)!/j!,j<i)
	LL ans=0;
	LL sv=0;
	//n k
	fo(i,0,k-1){
		LL tmp=quickmi(k-i,n)*inv[i]%mo*inv[k-i]%mo;
		if (i&1)sv=dec(sv,tmp);else sv=add(sv,tmp);
	}
//	cout<<sv<<endl;
	ans=sv;
	sv=0;
	//n-1 k
	fo(i,0,k-1){
		LL tmp=quickmi(k-i,n-1)*inv[i]%mo*inv[k-i]%mo;
		if(i&1)sv=dec(sv,tmp);else sv=add(sv,tmp);
	}
//	cout<<sv<<endl;
	ans=add(ans,sv*(n-1)%mo);
	LL sum=0;
	fo(i,1,n)sum=add(sum,a[i]);
	ans=ans*sum%mo;
	printf("%I64d\n",ans);
	return 0;
}