#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
//mt19937 mrand(random_device{}()); 
mt19937 mrand(1);
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010;
int n,a,b,c,f[N],g[N],mark[N];
vector<PII> ans;
VI z[10],ord,pos[10];
void add(int u,int v) {
	ans.pb(mp(u,v));
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d%d",&a,&b,&c);
		f[i]=a*4+b*2+c;
		//f[i]=rnd(8);
		//while (f[i]==0) f[i]=rnd(8);
		//if (i==0) f[i]=7;

		pos[f[i]].pb(i);
	}
	rep(i,0,n) {
		scanf("%d%d%d",&a,&b,&c);
		g[i]=a*4+b*2+c;
		//g[i]=rnd(8);
		//while ((g[i]&f[i])==0) g[i]=rnd(8);
		//if (i==0) g[i]=7;
		g[i]&=f[i];
	}
	z[7].pb(0);
	ord.pb(7);
	while (1) {
		bool alive=0;
		rep(i,1,8) if (z[i].empty()) {
			int bs=0;
			VI fa;
			rep(j,0,n) if (!z[f[j]].empty()&&(g[j]&i)==g[j]&&(g[j]|bs)!=bs) {
				bs|=g[j];
				fa.pb(j);
			}
			if (bs==i) {
				ord.pb(i);
				alive=1;
				z[i]=fa;
				//printf("zz %d\n",i);
				//for (auto x:fa) printf("%d:%d, ",x,g[x]); puts("");
			}
		}
		if (!alive) break;
	}
	for (auto x:ord) for (auto y:z[x]) mark[y]=1;
	rep(i,0,n) {
		if (f[i]&&z[f[i]].empty()) {
			puts("Impossible");
			return 0;
		}
	}
	for (auto x:ord) {
		int c=-1;
		for (auto y:pos[x]) if (!mark[y]) {
			c=y; break;
		}
		//printf("gg %d\n",c);
		if (x==7) {
			c=0;
			for (auto y:pos[x]) if (y!=c)
				add(c,y);
		} else {
			if (c==-1) {
				for (auto y:pos[x]) {
					for (auto zz:z[x]) add(zz,y);
				}
			} else {
				for (auto zz:z[x]) add(zz,c);
				for (auto y:pos[x]) if (y!=c)
					add(c,y);
			}
		}
	}
	puts("Possible");
	rep(i,0,n) printf("%d ",mark[i]); puts("");
	printf("%d\n",SZ(ans)); assert(SZ(ans)<=264);
	for (auto p:ans) printf("%d %d\n",p.fi+1,p.se+1);
}