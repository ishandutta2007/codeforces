#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1020000, mo = 998244353;
int n,fac[N],ifac[N];ll res;
int power(int a, int n){
	int res=1;
	while(n){if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;}
	return res;
}
int main() {
	read(n);fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	res=fac[n];
	rep(x,1,n-1)res=(res+1LL*fac[n]*ifac[n-x]%mo*(fac[n-x]-1))%mo;
	cout<<(res%mo+mo)%mo;
	return 0;
}