#include<bits/stdc++.h>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (int i=(x);i<(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define else else if(rand()%100000)
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
int n,m,a[N];
poly v[N];

inline void GG(){
	puts("NO");
	exit(0);
}

vector<pa>e[N];
poly vec;
inline void Add(int x,int y,int z){
	e[x].ep(y,z);
	e[y].ep(x,z);
}
int c[N],col[N];
inline void dfs(int u,int t){
	c[u]=t,vec.pb(u);
	for (auto [v,w]:e[u]){
		if (c[v]==-1) dfs(v,t^w);
		else if ((t^w)!=c[v]) GG();
	}
}

int main(){
	n=read(),m=read();
	For(i,1,n) a[i]=read();
	For(i,1,m){
		int cnt=read();
		For(j,1,cnt){
			int x=read();
			v[x].pb(i);
		}
	}
	fil(col,-1);
	For(i,1,n){
		if (a[i]==0){
			if (v[i].empty()) GG();
			if (siz(v[i])==1) col[v[i][0]]=1;
				else Add(v[i][0],v[i][1],1);
		} else {
			if (siz(v[i])==0) continue;
			if (siz(v[i])==1) col[v[i][1]]=0;
				else Add(v[i][0],v[i][1],0);
		}
	}
	fil(c,-1);
	For(i,1,m) if (c[i]==-1){
		vec.clear();
		dfs(i,0);
		bool flag=0;
		for (auto j:vec) if (col[j]!=-1){
			flag=1;break;
		}
		if (!flag) continue;
		bool f[2]={0,0};
		for (auto j:vec) if (col[j]!=-1) f[col[j]==c[j]]=1;
		if (f[0]&&f[1]) GG();
	}
	puts("YES");
}