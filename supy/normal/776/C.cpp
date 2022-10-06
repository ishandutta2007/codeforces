#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#include<map> 
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 100005 
int n,k;
int a[N];
ll pfix[N],ans;
map<ll,int> Map;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(k);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) pfix[i]=pfix[i-1]+a[i];
	for (ll w=1; abs(w)<=1e14; w*=k) {
		Map.clear(); Map[0]=1;
		rep(i,1,n) {
		//	if (Map.find(pfix[i]-w)!=Map.end())
			ans+=Map[pfix[i]-w];
			Map[pfix[i]]++;
		//	Map.insert(make_pair(pfix[i],1));
		}
		if (w==1&&k==1||k==-1&&w==-1) break;
	}
	printf("%lld",ans);
	return 0;
}