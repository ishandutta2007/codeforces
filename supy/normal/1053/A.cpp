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
const int N = 666;
int n,m,k;
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
void print(int a, int b){
	puts("YES");printf("0 0\n%d %d\n%d %d\n",a,0,0,b);
}
int solve(int n, int m, int k){
	if(2LL*n*m%k!=0){puts("NO");return 0;}
	int a,b;
	if(gcd(2*n,k)>1){int a=2*n/gcd(2*n,k);assert(a<=n&&2LL*n*m/k/a<=m);print(a,2LL*n*m/k/a);return 1;}
	if(gcd(2*m,k)>1){int b=2*m/gcd(2*m,k);assert(2LL*n*m/k/b<=n&&b<=m);print(2LL*n*m/k/b,b);return 1;}
}
int main() {
	read(n);read(m);read(k);solve(n,m,k);
	return 0;
}