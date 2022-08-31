#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
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

int cnt,p[100],mu[100],vis[100];
ll Pw[100010][41];
inline void init(){
	For(i,2,60){
		if (!vis[i]) p[++cnt]=i,mu[i]=-1;
		for (int j=1;j<=cnt&&i*p[j]<=60;++j){
			vis[i*p[j]]=1;
			if (i%p[j]==0) break;
			mu[i*p[j]]=-mu[i];
		}
	}
	ll lim=1e18;
	For(i,1,100002){
		Pw[i][0]=1;
		For(j,1,40){
			if (lim/i/Pw[i][j-1]>=1) Pw[i][j]=Pw[i][j-1]*i;
				else Pw[i][j]=lim+1;
		}
	}
}

int Las;
inline ll Pow(int x,int y){
	return Pw[x][y];
}
inline ll Sqrt(ll n,int k){
	if (k>=40){
		if ((1ll<<k)<=n) return 2;
		return 1;
	}
	if (k<=3){
		ll ret=pow(n,1.0/k)+2;
		while (233){
			ll x=n;
			For(i,1,k) x/=ret;
			if (!x) --ret;
				else break; 	
		}
		return ret;
	}
	ll ret=pow(n,1.0/k)+2;
	while (Pow(ret,k)>n) --ret;
	return ret;
}
inline void solve(){
	ll n=read();
	ll ans=n-1;
	For(i,2,60){
		Las=Sqrt(n,i);
		if (Las==1) break;
		ans+=mu[i]*(Las-1);
	}
	printf("%lld\n",ans);
}

int main(){
	init();
	int T=read();
	while (T--) solve();
}