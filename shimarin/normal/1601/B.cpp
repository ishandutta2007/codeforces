#include<bits/stdc++.h>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (int i=(x);i<(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
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
int n,a[N],b[N],c[N],dis[N];
queue<int>q;
pa pre[N];
poly v[N];

bool vis[N];
set<int>s;
inline void del(int p){
	if (vis[p]) return;
	vis[p]=1;
	for (auto i:v[p]) s.erase(i);
}
inline void dfs(int u){
	if (u==n) return;
	dfs(pre[u].se),printf("%d ",pre[u].fi);
}
inline void print(){
	printf("%d\n",dis[0]);
	dfs(0);
}

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) b[i]=read(),c[i]=i+b[i],v[c[i]].pb(i);
	For(i,0,n+1) s.insert(i);
	q.push(n),del(n),dis[n]=0;
	while (!q.empty()){
		int u=q.front();q.pop();
		int l=u-a[u],r=u-1;
		auto it=s.lower_bound(l);
		while (!s.empty()&&it!=s.end()){
			if (*it>r) break;
			dis[c[*it]]=dis[u]+1,q.push(c[*it]),pre[c[*it]]=mp(*it,u);
			if (*it==0){
				print();
				return 0;
			}
			del(c[*it]),it=s.lower_bound(l);
		}
	}
	puts("-1");
}