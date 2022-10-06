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
const int N = 666666, M = 66;
int n,a[N],cnt[2],qz[N];ll res=0;
int main() {
	read(n);rep(i,1,n){
		ll x;scanf("%lld",&x);rep(j,0,63)a[i]+=((x>>j)&1);qz[i]=(qz[i-1]+a[i])%2;
	}
	rep(i,1,n){
		if(i-M-1>=0)cnt[qz[i-M-1]]++;res+=cnt[qz[i]];
		int mx=0,tot=0;
		per(j,i,max(i-M+1,1)){tot+=a[j];mx=max(mx,a[j]);if(tot%2==0&&mx*2<=tot)res++;}
	}
	cout<<res;return 0;
}