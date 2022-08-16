#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
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
const int N = 1e6+10;
int n,m,vis[N];
inline void solve(){
	n=read(),m=read();
	For(i,1,n) vis[i]=0;
	For(i,1,m){
		int a=read(),b=read(),c=read();
		vis[b]=1;
	}
	For(i,1,n) if (!vis[i]){
		For(j,1,n) if (i!=j) printf("%d %d\n",i,j);
		break;
	}
}

int main(){
	int T=read();
	while (T--) solve();
}