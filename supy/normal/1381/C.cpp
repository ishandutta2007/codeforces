#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 2e5+77;
int n,x,y,vis[N],bh[N],a[N],b[N];Pii c[N];
priority_queue<Pii>heap;
Vi p[N];
int main() {
	int T;read(T);while(T--){
		read(n);read(x);read(y);
		while(!heap.empty())heap.pop();
		rep(i,0,n+2){
			p[i].clear();bh[i]=vis[i]=a[i]=b[i]=0;
		}
		rep(i,1,n){
			read(b[i]),vis[b[i]]++;c[i]=mp(vis[b[i]],i);bh[i]=vis[b[i]];
		}
		int ext=0;rep(i,1,n+1)if(!vis[i])ext=i;
		rep(i,1,n)a[i]=ext;
		sort(c+1,c+n+1);reverse(c+1,c+n+1);
		rep(i,1,x)a[c[i].se]=b[c[i].se],vis[b[c[i].se]]--;
		int tot=0,mx=0;rep(i,1,n+1)tot+=vis[i],umax(mx,vis[i]);
		if((mx*2<=tot?tot:(tot-mx)*2)<y-x){puts("NO");continue;}
		rep(i,1,n)if(a[i]==ext)p[b[i]].pb(i);
		rep(i,1,n+1)if(vis[i])heap.push(mp(vis[i],i));
		int need=y-x;
		//cerr<<need<<endl;
		while(need){
			Pii x=heap.top();heap.pop();
			Pii y=heap.top();heap.pop();
			if(x.fi==1&&y.fi==1&&SZ(heap)==1){
				Pii z=heap.top();heap.pop();
			//	cerr<<p[x.se].back()<<' '<<p[y.se].back()<<' '<<p[z.se].back()<<endl;
				if(need)need--,a[p[x.se].back()]=b[p[y.se].back()];
				if(need)need--,a[p[y.se].back()]=b[p[z.se].back()];
				if(need)need--,a[p[z.se].back()]=b[p[x.se].back()];
				break;
			}
			if(need)need--,a[p[x.se].back()]=b[p[y.se].back()];
			if(need)need--,a[p[y.se].back()]=b[p[x.se].back()];
			p[x.se].pop_back();
			p[y.se].pop_back();
			vis[x.se]--;vis[y.se]--;
			if(vis[x.se])heap.push(mp(vis[x.se],x.se));
			if(vis[y.se])heap.push(mp(vis[y.se],y.se));
		}
		assert(!need);
		puts("YES");rep(i,1,n)printf("%d ",a[i]);puts("");
	}
	return 0;
}