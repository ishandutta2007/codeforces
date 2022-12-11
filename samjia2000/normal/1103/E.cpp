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

typedef unsigned long long ull;

const int L = 10;
const int N = 1e5+5;
const ull D = 1ll<<58;
const ull Mod = (1ll<<58)-1;

ull W;
int n;
ull tmp[25];
struct poly{
	ull a[L];
	ull& operator [](int x){return a[x];}
	
	void init(){fo(i,0,9)a[i]=0;}
	
	friend poly operator *(poly a,poly b){
		poly c;
		fo(i,0,9)c[i]=0;
		fo(i,0,18)tmp[i]=0;
		fo(i,0,9)
			fo(j,0,9)tmp[i+j]+=a[i]*b[j];
		fo(i,0,9)c[i]=tmp[i];
		fo(i,10,18)c[i-10]+=tmp[i];
		return c;
	}
	friend poly operator + (poly a,poly b){
		poly c;
		fo(i,0,9)c[i]=a[i]+b[i];
		return c;
	}
	poly shift(int len){
		len=(len%10+10)%10;
		poly ret;
		fo(i,0,9)tmp[(i+len)%10]=a[i];
		fo(i,0,9)ret[i]=tmp[i];
		return ret;
	}
	
	ull calc(){
		fo(i,5,9){
			a[i-5]-=a[i];
			a[i]=0;
		}
		ull v=-a[1];
		fo(i,0,4)if (i&1)a[i]+=v;else a[i]-=v;
		ull ret=a[0];
		ret&=W;
		ret>>=5;
		fo(tim,1,5){
			for(;ret%5!=0;ret+=D);
			ret/=5;
		}
		return ret;
	}
}f[N],a[20],b[20];

poly quickmi(poly a,int tim){
	poly ret;
	ret.init();
	ret[0]=1;
	for(;tim;tim/=2,a=a*a)
		if (tim&1)ret=ret*a;
	return ret;
}

void DFT(poly *a){
	for(int i=0;i<10;i++){
		b[i].init();
		for(int j=0;j<10;j++)b[i]=b[i]+a[j].shift(i*j);
	}
	for(int i=0;i<10;i++)a[i]=b[i];
}

void IDFT(poly *a){
	DFT(a);
	reverse(a+1,a+10);
}

int main(){
//	freopen("data.in","r",stdin);
	W=1;
	fo(i,1,63)W=W*2;
	W--;
	n=get();
	fo(i,1,n){
		int x=get();
		f[x][0]++;
	}
	int Lim=1e5;
	for(int i=1;i<Lim;i*=10)
		for(int j=0;j<Lim;j+=i*10)
			for(int k=0;k<i;k++){
				fo(w,0,9)a[w]=f[j+k+i*w];
				DFT(a);
				fo(w,0,9)f[j+k+i*w]=a[w];
			}
	for(int i=0;i<Lim;i++)f[i]=quickmi(f[i],n);
	for(int i=1;i<Lim;i*=10)
		for(int j=0;j<Lim;j+=i*10)
			for(int k=0;k<i;k++){
				fo(w,0,9)a[w]=f[j+k+i*w];
				IDFT(a);
				fo(w,0,9)f[j+k+i*w]=a[w];
			}
	fo(i,0,n-1)printf("%I64d\n",f[i].calc());
	return 0;
}