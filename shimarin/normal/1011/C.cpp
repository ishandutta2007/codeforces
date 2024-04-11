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

const int N = 1010;
int n,m,a[N],b[N];

inline bool check(double x){
	For(i,1,n+1){
		double cost;
		if (i>1){
			int p=(i-1)%n+1;
			cost=(x+m)/b[p],x-=cost;
		}
		if (i<=n){
			cost=(x+m)/a[i],x-=cost;
		}	
	}
	if (x>=0) return 1;
	return 0;
}

int main(){
	n=read(),m=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) b[i]=read();
	double l=1,r=1e9,ans=-1;
	r+=10;
	For(i,1,100){
		double mid=(l+r)/2;
		if (check(mid)) ans=mid,r=mid;
			else l=mid;
	}
	if (ans==-1) return puts("-1"),0;
	printf("%lf\n",ans);
}