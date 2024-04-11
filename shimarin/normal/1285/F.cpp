//gosick
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
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 1e5+10;
int n,m,mx,a[N],cnt[N],top,stk[N],_cnt[N];
bool flag[N];
vector<int>v[N];

int mu[N],tot,p[N],vis[N];
inline void init(int n){
	mu[1]=1;
	For(i,2,n){
		if (!vis[i]) mu[i]=-1,p[++tot]=i;
		for (int j=1;j<=tot&&i*p[j]<=n;++j){
			vis[i*p[j]]=p[j];
			if (i%p[j]==0) break;
			mu[i*p[j]]=-mu[i];
		}
	}
}

int main(){
	n=read(),mx=0;
	For(i,1,n) cnt[a[i]=read()]++,m+=(cnt[a[i]]==1),mx=max(mx,a[i]);
	if (m==1) return printf("%d\n",a[1]),0;
	For(i,1,mx)
		For(j,1,mx/i) v[i*j].pb(i);
	init(mx);
	For(i,1,mx) if (cnt[i])
		for (auto j:v[i]) cnt[j]++;
	ll ans=0;
	Dow(i,mx,1) if (cnt[i]){
		int tot=0,las=0;
		for (auto j:v[i]) tot+=mu[j]*_cnt[j],flag[j]=1;
		while (top&&tot){
			for (auto j:v[stk[top]]) _cnt[j]--,tot-=flag[j]*mu[j];
			las=stk[top--];
		}
		if (!tot) ans=max(ans,1ll*i*las);
		stk[++top]=i;
		for (auto j:v[i]) _cnt[j]++,flag[j]=0;
	}
	printf("%lld\n",ans);
}