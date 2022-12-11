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

const LL Mod = 762939453125ll;
const int B = 873500;

LL Inv;

LL add(LL x,LL y,LL mo=Mod){return x+y>=mo?x+y-mo:x+y;}

LL multi(LL x,LL y,LL mo=Mod){
	LL ret=0;
	if (x<y)swap(x,y);
	for(;y;y/=2,x=add(x,x,mo))if (y&1)ret=add(ret,x,mo);
	return ret;
}

LL quickmi(LL x,LL tim,LL mo){
	LL ret=1;
	for(;tim;tim/=2,x=multi(x,x,mo))
	if (tim&1)ret=multi(ret,x,mo);
	return ret;
}

LL getk(LL x){
	LL phi=1,ret=0,now=1,mo=1;
	fo(s,1,17){
		mo=mo*5;
		LL ad=quickmi(2,phi,mo);
		LL v=quickmi(2,ret,mo);
		fo(c,0,4){
			if (v==x%mo)break;
			ret+=phi;
			v=multi(v,ad,mo);
		}
		if (s==1)phi=4;else phi=phi*5;
	}
	return ret;
}

void solve(){
	LL a;
	cin>>a;
	int n=1;
	for(LL now=10;now<=a;now*=10,n++);
	int m=17-n;
	LL n2=1,m2=1;
	LL m10=1;
	fo(i,1,n)n2=n2*2;
	fo(i,1,m)m2=m2*2,m10=m10*10;
	LL b=a%n2;
	fo(i,1,m)b=multi(b,5,n2);
	b=(n2-b)%n2;
	b=b*m2;
	LL ad=1;
	fo(i,1,n+m)ad=ad*2;
	while((a*m10+b)%5==0)b=b+ad;
	LL x=a*m10+b;
	x=x/ad;
	cout<<getk(x)+n+m<<endl;
}

int main(){
	//freopen("data.in","r",stdin);
	for(int T=get();T;T--)solve();
	return 0;
}