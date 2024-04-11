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

const int N = 2e5+10;
int n,m,l[N],r[N],s[N],f[N],g[N];

int c[N];
inline void Add(int x,int y){
	for (++x;x<=n;x+=x&-x) c[x]=max(c[x],y);
}
inline int Query(int x){
	int ret=0;
	for (++x;x;x-=x&-x) ret=max(ret,c[x]);
	return ret;
}

int main(){
	n=read(),m=read();
	For(i,1,n){
		l[i]=read(),r[i]=read();
		s[l[i]]++,s[r[i]+1]--;
	}
	int ans=0;
	For(i,1,m){
		s[i]+=s[i-1];
		f[i]=Query(s[i])+1;
		Add(s[i],f[i]);
	}
	fil(c,0);
	Dow(i,m,1){
		g[i]=Query(s[i])+1;
		Add(s[i],g[i]);
	}
	For(i,1,m) ans=max(ans,f[i]+g[i]-1);
	printf("%d\n",ans);
}