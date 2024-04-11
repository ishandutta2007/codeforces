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
int n,a[N],b[N],k;char S[N];
bool ck(int *b){
	rep(i,1,n)if(a[i]!=b[i])return b[i]>a[i];return 1;
}
void print(int *b, int n){printf("%d\n",n);rep(i,1,n)printf("%d",b[i]);exit(0);}
int main() {
	read(n);read(k);scanf("%s",S+1);
	rep(i,1,n)a[i]=S[i]-'0';
	rep(i,1,n)b[i]=a[i%k?i%k:k];
	if(ck(b)){print(b,n);return 0;}
	bool ok=0;rep(i,1,k)ok|=a[i]<9;
	if(ok){
		a[k]++;
		for(int i=k;i&&a[i]>9;i--)a[i-1]++,a[i]-=10;
		rep(i,1,n)b[i]=a[i%k?i%k:k];
		print(b,n);return 0;
	}
	n++;
//	rep(i,1,n)b[i]=i%k==1?1:0;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i+=k)b[i]=1;
	print(b,n);
	return 0;
}