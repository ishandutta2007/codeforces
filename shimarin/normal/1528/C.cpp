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

const int N = 3e5+10;
int n;
poly e1[N],e2[N];

int cnt,l[N],r[N];
inline void dfs2(int u){
	l[u]=++cnt;
	for (auto v:e2[u]) dfs2(v);
	r[u]=cnt;
}
int ans;
set<pa>s;
inline void dfs(int u){
	pa del={-1,-1},add={-1,-1};
	if (!s.empty()){
		auto it=s.lower_bound(mp(l[u],0));
		if (it!=s.end()&&it->se<=r[u]){

		} else {
			it=s.upper_bound(mp(l[u],n+1));
			if (it!=s.begin()){
				--it;
				if (it->se>=r[u]) del=*it,s.erase(it);
				add={l[u],r[u]},s.insert(add);
			} else add={l[u],r[u]},s.insert(add);
		}
	} else add={l[u],r[u]},s.insert(add);
	ans=max(ans,siz(s));
	for (auto v:e1[u]) dfs(v);
	if (~del.fi) s.insert(del);
	if (~add.fi) s.erase(add);
}
inline void solve(){
	n=read();
	For(i,1,n) e1[i].clear(),e2[i].clear();
	For(i,2,n) e1[read()].pb(i);
	For(i,2,n) e2[read()].pb(i);
	cnt=0,dfs2(1);
	ans=1,dfs(1),printf("%d\n",ans);
}

int main(){
	int T=read();
	while (T--) solve();
}
/*
1
5
1 2 3 4
1 1 1 1
*/