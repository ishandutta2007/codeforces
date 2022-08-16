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
const ll lim = 1e18;
int n,k,a[N];
ll pre[N],pw[N];
map<ll,int>f;

int main(){
	n=read(),k=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) pre[i]=pre[i-1]+a[i];
	ll x=1;
	int cnt=1;
	pw[cnt]=x;
	if (k==1){

	} else if (k==-1){
		pw[++cnt]=-1;
	} else {
		while (abs(x)<=lim/abs(k)) x*=k,pw[++cnt]=x;
	}
	f[pre[0]]++;
	ll ans=0;
	For(i,1,n){
		For(j,1,cnt) ans+=f[pre[i]-pw[j]];
		f[pre[i]]++;
	}
	printf("%lld\n",ans);
}