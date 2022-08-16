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
int n,m,op[N],f[N];
ll x[N],y[N];

int main(){
	n=read(),m=read();
	For(i,1,n) op[i]=read(),x[i]=read(),y[i]=read();
	queue<pa>q;
	fil(f,-1),f[0]=0,q.push(mp(0,1));
	while (!q.empty()){
		int u=q.front().fi,i=q.front().se;q.pop();
		if (op[i]==1){
			ll v=u;
			For(j,1,y[i]){
				v=ceil(v+1.0*x[i]/100000);
				if (v>m) break;
				if (f[v]==-1) q.push(mp(v,i+1)),f[v]=i;
					else break;
			}
			if (i<n) q.push(mp(u,i+1));
		} else {
			ll v=u;
			For(j,1,y[i]){
				v=ceil(1.0*v*x[i]/100000);
				if (v>m) break;
				if (f[v]==-1) q.push(mp(v,i+1)),f[v]=i;
					else break;
			}
			if (i<n) q.push(mp(u,i+1));
		}
	}
	For(i,1,m) printf("%d ",f[i]);puts("");
}