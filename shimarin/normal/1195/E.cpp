#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 3010;
int n,m,p,q,g[N*N],x,y,z;

int h,t,qu[N],a[N][N],b[N][N];
inline void Getb(){
	For(i,1,n){
		h=1,t=0;
		For(j,1,m){
			while (h<=t&&a[i][j]<a[i][qu[t]]) --t;
			qu[++t]=j;
			if (qu[h]<j-q+1) ++h;
			if (j>=q) b[i][j-q+1]=a[i][qu[h]];
		}
	}
}

ll ans;
inline void Getc(){
	For(j,1,m-q+1){
		h=1,t=0;
		For(i,1,n){
			while (h<=t&&b[i][j]<b[qu[t]][j]) --t;
			qu[++t]=i;
			if (qu[h]<i-p+1) ++h;
			if (i>=p) ans+=b[qu[h]][j]; 
		}
	}
}

int main(){
	n=read(),m=read(),p=read(),q=read();
	g[0]=read(),x=read(),y=read(),z=read();
	FOR(i,1,n*m) g[i]=(1ll*g[i-1]*x+y)%z;
	For(i,1,n)
		For(j,1,m) a[i][j]=g[(i-1)*m+j-1];
	Getb(),Getc();
	printf("%lld\n",ans);
}