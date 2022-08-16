#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
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
int n,a[N],vis[N],cnt,ans[N],r[N];
inline int calc(int x){
	return __gcd(a[r[x]],a[x]);
}
inline void del(int x){
	vis[r[x]]=1,r[x]=r[r[x]];
}
inline void solve(){
	n=read();
	For(i,1,n){
		a[i]=read();
		r[i]=i+1,vis[i]=0;
	}
	r[n]=1;
	queue<int>q;
	For(i,1,n) if (calc(i)==1) q.push(i);
	cnt=0;
	while (!q.empty()){
		int u=q.front();q.pop();
        if (vis[u]) continue;
        ans[++cnt]=r[u],del(u);
        if (calc(u)==1) q.push(u);
	}
	printf("%d ",cnt);
	For(i,1,cnt) printf("%d ",ans[i]);puts("");
}

int main(){
	int T=read();
	while (T--) solve();
}