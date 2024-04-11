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
const int M = 40;
bitset<7003>a[100200],b[M+5];
Vi fac[7070];
const int N = 7007;
int n,q,prime[N],mrk[N],len,mu[N];
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i,mu[i]=-1;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	mu[1]=1;
	int cnt=0;rep(i,1,n)cnt+=mu[i]!=0;cerr<<cnt;
}
int main() {
	getp(N-1);read(n);read(q);
	rep(v,1,M)per(i,7000/v,1)b[v][v*i]=(mu[i]+2)%2;
	rep(i,1,7000)for(int j=i;j<=7000;j+=i)fac[j].pb(i);
	while(q--){
		int op,x;read(op);read(x);
		if(op==1){
			int v;read(v);a[x].reset();
			rep(i,0,SZ(fac[v])-1)a[x][fac[v][i]]=1;
		}
		if(op==2){
			int y,z;read(y);read(z);
			a[x]=a[y]^a[z];
		}
		if(op==3){
			int y,z;read(y);read(z);
			a[x]=a[y]&a[z];
		}
		if(op==4){
			int v;read(v);int r=0;
			if(v>M){per(i,7000/v,1)r+=mu[i]*a[x][v*i];}
			else{
				r=(a[x]&b[v]).count();
			}
			printf("%d",(r%2+2)%2);
		}
	}
	return 0;
}