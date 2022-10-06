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
const int N = 66666;
int n,a[N],b[N],cnt[N],s[N],len,c[N],size;
void GG(){puts("NO");exit(0);}
int Get(int &p){
	while(cnt[p])p++;p++;return p-1;
}
Vi x,y;
int main() {
	read(n);rep(i,1,n-1)read(a[i]),read(b[i]);
	rep(i,1,n-1)if(b[i]!=n)GG();
	rep(i,1,n-1)cnt[a[i]]++;
	rep(i,1,n-1)if(cnt[i])s[++len]=i;int p=1;
	rep(t,1,len){
		c[++size]=s[t];rep(i,1,cnt[s[t]]-1)c[++size]=Get(p);
	}
	c[++size]=n;rep(i,1,n-1)x.pb(a[i]);
	rep(i,1,n-1){
		int v=0;rep(j,1,i)v=max(v,c[j]);y.pb(v);
	}
	sort(x.begin(),x.end());sort(y.begin(),y.end());
	per(i,SZ(x)-1,0)if(x[i]!=y[i])GG();
	puts("YES");rep(i,1,n-1)printf("%d %d\n",c[i],c[i+1]);
	return 0;
}