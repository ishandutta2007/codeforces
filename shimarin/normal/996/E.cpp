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

const int N = 1e5+10;
int n,ans[N];
ll p[N],q[N],pos[N];

inline ll sqr(ll x){
	return x*x;
}
inline ll calc(ll x,ll y){
	return sqr(x)+sqr(y);
}

int main(){
	n=read();
	For(i,1,n) p[i]=read(),q[i]=read(),pos[i]=i;
	For(j,1,100){
		random_shuffle(pos+1,pos+1+n);
		ll x=0,y=0;
		For(i,1,n){
			ll a=p[pos[i]],b=q[pos[i]];
			if (calc(x+a,y+b)<calc(x-a,y-a)) ans[pos[i]]=1,x+=a,y+=b;
				else ans[pos[i]]=-1,x-=a,y-=b;
		}
		if (calc(x,y)<=sqr(1500000)){
			For(i,1,n) printf("%d ",ans[i]);
			return 0;
		}
	}
}