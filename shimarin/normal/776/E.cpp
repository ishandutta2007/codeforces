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

inline ll phi(ll n){
	ll ret=n;
	for (ll i=2;i*i<=n;i++){
		if (n%i==0){
			while (n%i==0) n/=i;
			ret=ret/i*(i-1);
		}
	}
	if (n>1) ret=ret/n*(n-1);
	return ret;
}

const int mod = 1e9+7;

int main(){
	ll n=read(),k=read();
	ll now=phi(n);
	for (ll i=2;i<=k;++i){
		if (i%2==0) continue;
		now=phi(now);
		if (now==1) break;
	}
	printf("%lld\n",now%mod);
}