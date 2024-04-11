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

const int N = 2e4+10;
int n,x,y,top,stk[N],l[N],r[N];
char s[N];

int cnt,ls[N],rs[N],p[N];
inline int Build(int l,int r){
	int u=++cnt;
	if (s[l+1]>='0'&&s[l+1]<='9'){
		++cnt,ls[u]=cnt,p[cnt]=s[l+1]-'0';
	} else {
		ls[u]=Build(l+1,::r[l+1]);
	}
	if (s[r-1]>='0'&&s[r-1]<='9'){
		++cnt,rs[u]=cnt,p[cnt]=s[r-1]-'0';
	} else {
		rs[u]=Build(::l[r-1],r-1);
	}
	return u;
}

namespace solve1{
	const int inf = 1e9;
	int mx[N][110],mn[N][110];
	inline void Dfs(int u){
		For(i,0,x) mx[u][i]=-inf,mn[u][i]=inf;
		if (p[u]!=-1) return mx[u][0]=mn[u][0]=p[u],void(0);
		Dfs(ls[u]),Dfs(rs[u]);
		For(i,0,x) For(j,0,x-i){
			mx[u][i+j]=max(mx[u][i+j],mx[ls[u]][i]-mn[rs[u]][j]);
			mx[u][i+j+1]=max(mx[u][i+j+1],mx[ls[u]][i]+mx[rs[u]][j]);
			mn[u][i+j]=min(mn[u][i+j],mn[ls[u]][i]-mx[rs[u]][j]);
			mn[u][i+j+1]=min(mn[u][i+j+1],mn[ls[u]][i]+mn[rs[u]][j]);
		}
	}
	inline void solve(){
		Dfs(1),printf("%d\n",mx[1][x]);
	}
}

namespace solve2{
	const int inf = 1e9;
	int mx[N][110],mn[N][110];
	inline void Dfs(int u){
		For(i,0,y) mx[u][i]=-inf,mn[u][i]=inf;
		if (p[u]!=-1) return mx[u][0]=mn[u][0]=p[u],void(0);
		Dfs(ls[u]),Dfs(rs[u]);
		For(i,0,y) For(j,0,y-i){
			mx[u][i+j+1]=max(mx[u][i+j+1],mx[ls[u]][i]-mn[rs[u]][j]);
			mx[u][i+j]=max(mx[u][i+j],mx[ls[u]][i]+mx[rs[u]][j]);
			mn[u][i+j+1]=min(mn[u][i+j+1],mn[ls[u]][i]-mx[rs[u]][j]);
			mn[u][i+j]=min(mn[u][i+j],mn[ls[u]][i]+mn[rs[u]][j]);
		}
	}
	inline void solve(){
		Dfs(1),printf("%d\n",mx[1][y]);
	}
}

int main(){
	scanf("%s",s+1),n=strlen(s+1),x=read(),y=read();
	if (n==1) return printf("%d\n",s[1]-'0'),0;
	For(i,1,n){
		if (s[i]=='(') stk[++top]=i;
		else if (s[i]==')') r[stk[top]]=i,l[i]=stk[top],--top;
	}
	fil(p,-1);
	int rt=Build(1,n);
	if (x<y) solve1::solve();
		else solve2::solve();
}