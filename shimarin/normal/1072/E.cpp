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

const int M = 1e5+10;
int n,a[M];
vector<pair<pa,int>>ans;

inline void GG(){
	puts("NO");exit(0);
}

const int N = 1<<12;
int dis[N],Dis[N];
pair<pa,int>las[N],Las[N];
inline void init(int n){
	FOR(i,0,1<<n) dis[i]=1e9;
	queue<int>q;
	dis[0]=0,q.push(0);
	while (!q.empty()){
		int u=q.front();q.pop();
		For(i,1,n){
			For(j,i+1,n){
				int k=j+j-i;
				if (k>n) break;
				int to=u^(1<<i-1)^(1<<j-1)^(1<<k-1);
				if (dis[to]==1e9) dis[to]=dis[u]+1,las[to]=mp(mp(i,j),k),q.push(to);
			}
		}
	}
}

inline void init2(){
	FOR(i,0,1<<6) Dis[i]=1e9;
	queue<int>q;
	Dis[0]=0,q.push(0);
	while (!q.empty()){
		int u=q.front();q.pop();
		For(i,1,12){
			For(j,i+1,12){
				int k=j+j-i;
				if (k>12) break;
				int to=u^(1<<i-1)^(1<<j-1)^(1<<k-1);
				to&=((1<<6)-1);
				if (Dis[to]==1e9) Dis[to]=Dis[u]+1,Las[to]=mp(mp(i,j),k),q.push(to);
			}
		}
	}
}

inline void solve1(){
	init(n);
	int x=0;
	For(j,1,n) x|=a[j]<<(j-1);
	if (dis[x]==1e9) GG();
	while (x){
		ans.pb(mp(mp(las[x].fi.fi,las[x].fi.se),las[x].se));
		x=x^(1<<las[x].fi.fi-1)^(1<<las[x].fi.se-1)^(1<<las[x].se-1);
	}
	puts("YES");
	printf("%d\n",siz(ans));
	for (auto i:ans) printf("%d %d %d\n",i.fi.fi,i.fi.se,i.se);
}

int main(){
	n=read();
	For(i,1,n) a[i]=read();
//	n=100;
//	For(i,1,n) a[i]=rand()%2;
	if (n<=12) return solve1(),0;
	int l=1;
	init2();
	while (233){
		if (n-l+1<=12){
			l=n-11;
			int x=0;
			For(j,l,n) x|=a[j]<<(j-l);
			init(n-l+1);
			//For(j,l,n) printf("%d",a[j]);puts("");
			if (dis[x]==1e9) GG();
			while (x){
				ans.pb(mp(mp(las[x].fi.fi+l-1,las[x].fi.se+l-1),las[x].se+l-1));
				a[las[x].fi.fi+l-1]^=1,a[las[x].fi.se+l-1]^=1,a[las[x].se+l-1]^=1;
				x=x^(1<<las[x].fi.fi-1)^(1<<las[x].fi.se-1)^(1<<las[x].se-1);
			}
			break;
		}
		int x=0;
		For(j,l,l+5) x|=a[j]<<(j-l);
		while (x){
			ans.pb(mp(mp(Las[x].fi.fi+l-1,Las[x].fi.se+l-1),Las[x].se+l-1));
			a[Las[x].fi.fi+l-1]^=1,a[Las[x].fi.se+l-1]^=1,a[Las[x].se+l-1]^=1;
			x=x^(1<<Las[x].fi.fi-1)^(1<<Las[x].fi.se-1)^(1<<Las[x].se-1);
			x&=(1<<6)-1;
		}
		l+=6;
	}
	puts("YES");
	printf("%d\n",siz(ans));
	for (auto i:ans) printf("%d %d %d\n",i.fi.fi,i.fi.se,i.se);
//	For(i,1,n) printf("%d",a[i]);
}