#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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

const int N = 2e5+10, mod = 1e9+7;
int n,a[N],nxt[N],s[N],f[N];
ll pre[N];

inline int Mod(int x){
	return x>=mod?x-mod:x;
}
inline void Add(int x,int y){
	for (;x<=n+1;x+=x&-x) s[x]=Mod(s[x]+y);
}
inline int Query(int x){
	int ret=0;
	for (;x;x-=x&-x) ret=Mod(ret+s[x]);
	return ret;
}
inline void solve(){
	n=read();
	For(i,1,n) a[i]=read(),pre[i]=pre[i-1]+a[i];
	map<ll,int>now;
	Dow(i,n,1){
		if (a[i]==0){
			nxt[i]=i+1;
			continue;
		}
		if (!now.count(pre[i-1])) now[pre[i-1]]=n;
		nxt[i]=now[pre[i-1]]+1;
		now[pre[i]]=i;
	}
	nxt[n+1]=n+1;
	For(i,1,n+1) s[i]=0;
	f[1]=1;
	For(i,1,n+1){
		if (i>=2) f[i]=Query(i);
		Add(i+1,f[i]),Add(nxt[i]+1,mod-f[i]);
	}
	printf("%d\n",f[n+1]);
}

int main(){
	int T=read();
	while (T--) solve();
}