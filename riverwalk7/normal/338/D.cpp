#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n,m,x,y,d,X,Y,a[10100];
int k;
inline LL exgcd(LL a,LL b,LL &x,LL &y){
	if(!b) {x=1,y=0;return a;}
	LL tp=exgcd(b,a%b,x,y);
	LL t=x;x=y;y=t-a/b*x;
	return tp;
}

int main()
{
	cin >> n >> m >> k >> a[1];X=a[1];
	if(X>n) return puts("NO"),0;
	for(int i=2;i<=k;i++){
		cin >> a[i];
		d=exgcd(X,a[i],x,y);
		if((i-1+Y)%d) return puts("NO"),0;
		x=(x*(-i+1-Y)/d)%(a[i]/d);
		Y+=x*X;X=X/d*a[i];
		if(X>n) return puts("NO"),0;
		Y=(Y%X+X)%X;
	}
	if(!Y) Y=X;
	if(Y+k-1>m) return puts("NO"),0;
	for(int i=1;i<=k;i++) if(__gcd(X,Y+i-1)!=a[i]) return puts("NO");
	puts("YES");
	return 0;
}