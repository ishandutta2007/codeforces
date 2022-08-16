#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
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
int n,k,a[N],nxt[N];
ll pre[N];

inline int check(int l,int L,int R,__int128 x){
	if (x%k) return 0;
	if (!binary_search(pre+L,pre+R+1,x+pre[l-1])) return 0;
	return 1;
}

int main(){
	n=read(),k=read();
	For(i,1,n) a[i]=read(),pre[i]=pre[i-1]+a[i];
	For(i,1,n) pre[i]*=k;
	nxt[n+1]=n+1;
	Dow(i,n,1)
		if (a[i]!=1) nxt[i]=i;
			else nxt[i]=nxt[i+1];
	int ans=0;
	For(i,1,n){
		__int128 x=a[i];
		int now=i;
		while (x<=pre[n]&&now<=n){
			int L=now,R=nxt[now+1]-1;
			ans+=check(i,L,R,x);
			now=R+1,x=x*a[now];
		}
	}
	printf("%d\n",ans);
}