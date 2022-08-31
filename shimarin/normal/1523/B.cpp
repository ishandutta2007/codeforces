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

inline void solve(){
	int n=read();
	poly a(n+1);
	For(i,1,n) a[i]=read();
	vector<pair<int,pa>>ans;
	for (int i=1;i<=n;i+=2){
		int j=i+1;
		ans.pb({1,{i,j}});
		ans.pb({2,{i,j}});
		ans.pb({1,{i,j}});
		ans.pb({1,{i,j}});
		ans.pb({2,{i,j}});
		ans.pb({1,{i,j}});
	}
	printf("%d\n",siz(ans));
	for (auto i:ans) printf("%d %d %d\n",i.fi,i.se.fi,i.se.se);
}

int main(){
	int T=read();
	while (T--) solve();
}