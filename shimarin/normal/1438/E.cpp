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

const int N = 1e6+10;
int n,a[N];
ll pre[N];

inline bool check(int l,int r){
	if ((a[l]^a[r])==pre[r-1]-pre[l]) return 1;
	return 0;
}

int main(){
	n=read();
	For(i,1,n) a[i]=read(),pre[i]=pre[i-1]+a[i];
//	n=2e5;
//	For(i,1,n) a[i]=rand();
	For(i,1,n) pre[i]=pre[i-1]+a[i];
	For(i,n+1,2*n) pre[i]=1e18;

	int ans=0;
	For(i,2,n-1){
		int now=i-1;
		ans+=check(now,2*i-now);
		ll s=pre[2*i-now]-pre[now-1];
		int cnt=0;
		while (now>1){
			int l=1,r=now,ret=0;
			while (l<=r){
				int mid=l+r>>1;
				if (pre[2*i-mid]-pre[mid-1]>=2*s) ret=mid,l=mid+1;
					else r=mid-1;
			}
			if (ret<=0||pre[2*i-ret]==1e18) break;
			now=ret,s=pre[2*i-now]-pre[now-1];
			ans+=check(now,2*i-now);
		}
	}

	For(i,2,n-2){
		int now=i-1;
		ans+=check(now,2*i-now+1);
		ll s=pre[2*i-now+1]-pre[now-1];
		while (now>1){
			int l=1,r=now,ret=0;
			while (l<=r){
				int mid=l+r>>1;
				if (pre[2*i-mid+1]-pre[mid-1]>=2*s) ret=mid,l=mid+1;
					else r=mid-1;
			}
			if (ret<=0||pre[2*i-ret+1]==1e18) break;
			now=ret,s=pre[2*i-now+1]-pre[now-1];
			ans+=check(now,2*i-now+1);
		}
	}

	printf("%d\n",ans);
}