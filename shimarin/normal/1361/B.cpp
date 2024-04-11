//
#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) cout<<#v<<":";for (auto i:v) cout<<i<<" ";puts("")
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

const int N = 1e6+10, mod = 1e9+7;
int n,m,a[N],cnt,b[N],c[N];

inline int power(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) ret=1ll*ret*a%mod;
	return ret; 
}

inline void solve(){
	n=read(),m=read();
	For(i,1,n) a[i]=read();
	if (m==1){
		if (n&1) printf("%d\n",1);
			else printf("%d\n",0);
		return;
	}
	sort(a+1,a+1+n);
	b[cnt=0]=-1;
	For(i,1,n)
		if (a[i]!=b[cnt]) ++cnt,b[cnt]=a[i],c[cnt]=1;
			else c[cnt]++;
	bool f=1;
	Dow(i,cnt,1){
		if (c[i]%2){
			int p=1,flag=1;
			Dow(j,i-1,1){
				For(k,1,b[j+1]-b[j]){
					if (p>n/m){flag=0;break;}
					p=p*m;
				}
				if (!flag) break;
				if (c[j]>=p){
					FOR(k,j+1,i) c[k]=0;
					c[j]-=p,c[i]--;
					break;
				} else p-=c[j];
			}
			if (c[i]%2){
				f=0;break;
			}
		}
	}
	int ans=0,pos=0;
	if (!f){
		Dow(i,cnt,1) if (c[i]%2){
			ans=power(m,b[i]),pos=i;break;
		}
		FOR(i,1,pos) ans=(ans+mod-1ll*c[i]*power(m,b[i])%mod)%mod;
		printf("%d\n",ans);
	} else puts("0");
}

int main(){
	int T=read();
	while (T--) solve();
}