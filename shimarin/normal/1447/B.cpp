#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
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

const int N = 110;
int n,m,a[N][N];

inline void solve(){
	n=read(),m=read();
	int mn=1e9,s=0,cnt=0;
	For(i,1,n){
		For(j,1,m){
			a[i][j]=read();
			cnt+=(a[i][j]<0);
			mn=min(mn,abs(a[i][j]));
			s+=abs(a[i][j]);
		}
	}
	if (cnt&1) s-=2*mn;
	printf("%d\n",s);
}

int main(){
	int T=read();
	while (T--) solve();
}