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

const int N = 1010, mod = 1e9+7;
int n,k,f[N][N],pre[N][N];
inline void solve(){
	n=read(),k=read();
	For(i,0,n) f[i][1]=1,pre[i][1]=i+1;
	For(j,2,k){
		f[0][j]=pre[0][j]=1;
		For(i,1,n){
			f[i][j]=(1+(1ll*pre[n-1][j-1]+mod-(n-i==0?0:pre[n-i-1][j-1])))%mod;
			pre[i][j]=(pre[i-1][j]+f[i][j])%mod;
		}
	}
	printf("%d\n",f[n][k]);
}

int main(){
	int T=read();
	while (T--) solve();
}