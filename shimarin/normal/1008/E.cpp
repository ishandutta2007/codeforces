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
 
inline int Query(ll x,ll y){
	printf("%lld %lld\n",x,y),fflush(stdout);
	int ret=read();
	if (ret==0) exit(0);
	return ret;
}
 
int main(){
	ll n=read();
	ll x=0,y=0,dx=1,dy=1;
	while (233){
		int ans=Query(x+dx,y+dy);
		if (ans==1) x+=dx,dx=min(n-x,2*dx);
		if (ans==2) y+=dy,dy=min(n-y,2*dy);
		if (ans==3) dx=max(1ll,dx/2),dy=max(1ll,dy/2);
	}
}