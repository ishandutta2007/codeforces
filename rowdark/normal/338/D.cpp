#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

inline LL Gcd(LL x,LL y){
	if(!y) return x;
	register LL z;
	while(z=x%y) x=y,y=z;
	return y;
}
const LL maxn=0x3fffffffffffffffLL;
void extend_gcd(LL x,LL y,LL& z,LL& w){
	if(!y) {z=1,w=0;}
	else
	{
		extend_gcd(y,x%y,w,z);
		w=-(z*(x/y))-w;
		z=-z;
	}
}
struct fun{
	LL p,x;
	fun(LL _p,LL _x):p(_p),x(_x){if(x>=p||x<=-p) x%=p;if(x<0) x+=p;}
};
LL by(LL a,LL b,LL c){
	a%=c,b%=c;
	if(a<0) a+=c;
	if(b<0) b+=c;
	LL d=0;
	while(b)
	{
		if(b&1)if(c<=(d+=a)) d-=c;
		a<<=1;
		if(c<=a) a-=c;
		b>>=1;
	}
	return d;
}
inline bool unionfun(fun &a,const fun &b){
	LL A=a.p,B=b.p,C=b.x-a.x,D=Gcd(A,B);
	if(C%D!=0) return false;
	A/=D,B/=D,C/=D;
	LL fa,fb;
	extend_gcd(A,B,fa,fb);
	fa=by(C,fa,B);
	return a=fun(a.p/D*b.p,a.p*fa+a.x),1;
}
LL n,m;
LL a[10001];
int k;
inline bool solve(){
	fun O(1,0);
	for(int i=0;i<k;++i)
	{
		LL x,d;
		cin>>x;
		d=Gcd(O.p,x);
		if(n/O.p<x/d) return false;
		if(!unionfun(O,fun(x,-(i)))) return false;
		a[i]=x;
	}
	if(O.x==0) O.x+=O.p;
	if(O.p>n||O.x+k-1>m) return false;
	for(int i=0;i<k;++i) if(Gcd(O.p,O.x+i)!=a[i]) return false;
	return true;
}
int main(){

#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
        printf("%s\n",solve()?"YES":"NO");
}