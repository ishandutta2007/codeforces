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
const int N = 5555;
struct Pii{
	int x,y;Pii(int X=0,int Y=0){x=X;y=Y;}
};
int n;Pii s[N],a[N];ll res;
ll cross(const Pii &a,const Pii &b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
bool cmp(const Pii &a,const Pii &b){
	if((a.y>=0)^(b.y>=0))return a.y>=0;
	return cross(a,b)>0;
}
ll f(int x){return x>=2?1LL*x*(x-1)>>1:0LL;}
void solve(int n){
	rep(i,n+1,n+n)s[i]=s[i-n];
	for(int i=1,j=1;i<=n;i++){
		while(j+1<i+n&&cross(s[i],s[j+1])>=0)j++;
		//printf("<%d>\n",j-i);
		res+=1LL*f(j-i)*f(n-1-(j-i));
	}
}
int main() {
	read(n);rep(i,1,n)read(a[i].x),read(a[i].y);
	rep(i,1,n){
		int len=0;rep(j,1,n)if(i!=j)s[++len]=Pii(a[j].x-a[i].x,a[j].y-a[i].y);
		sort(s+1,s+len+1,cmp);
		solve(len);
	}
	cout<<res/2;
	return 0;
}