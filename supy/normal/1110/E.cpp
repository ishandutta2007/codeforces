#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int n,a[N],b[N],A[N],B[N];
bool ck(){
	if(a[1]!=b[1])return 0;
	rep(i,2,n)A[i]=a[i]-a[i-1];A[1]=-1e9;
	rep(i,2,n)B[i]=b[i]-b[i-1];B[1]=-1e9;
	sort(A+1,A+n+1);sort(B+1,B+n+1);
	rep(i,1,n)if(A[i]!=B[i])return 0;
	return 1;
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	if(ck())puts("Yes");else puts("No");
	return 0;
}