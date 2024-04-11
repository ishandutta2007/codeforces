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

const int N = 3e5+10;
int n,m,k,a[N];
ll pre[N];

ll mx[N];
inline void Add(int x){
	mx[x%m]=max(mx[x%m],-1ll*pre[x]*m+1ll*k*x);
}

int main(){
	n=read(),m=read(),k=read();
	For(i,1,n) a[i]=read(),pre[i]=pre[i-1]+a[i];
	ll ans=0;
	FOR(i,0,m) mx[i]=-1e18;
	Add(0);
	For(i,1,n){
		FOR(j,0,m) 
			if (i%m!=j) ans=max(ans,pre[i]*m-1ll*k*i+mx[j]-1ll*k*((m-(i%m-j+m)%m)));
				else ans=max(ans,pre[i]*m-1ll*k*i+mx[j]);
		Add(i);
	}
	printf("%lld\n",ans/m);
}