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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int _,n;
int mark[1010][1010];
//int p[1010],rk[1010];
VI los,dd;
bool query(int x,int y) {
	if (x==y) return 0;
	if (mark[x][y]==-1) {
		printf("? %d %d\n",x+1,y+1);
		fflush(stdout);
		char c[10];
		scanf("%s",c);
		//c[0]=p[x]<p[y]?'<':'>';
		if (c[0]=='<') {
			mark[x][y]=1; mark[y][x]=0;
		} else {
			mark[x][y]=0; mark[y][x]=1;
		}
	}
	return mark[x][y];
}
void finished() {
	puts("!");
	/*bool al=1;
	rep(i,0,2*n) printf("%d ",rk[i]+1); puts("");
	for (auto x:los) printf("%d ",x+1); puts("");
	rep(i,n,2*n-1) {
		printf("%d ",mark[rk[i+1]][rk[i]]);
		al&=mark[rk[i+1]][rk[i]]==0;
	}
	puts("");
	assert(!al);
	for (auto x:dd) assert(p[x]>=n);*/
	fflush(stdout);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,0,2*n) rep(j,0,2*n) mark[i][j]=-1;
		//rep(i,0,2*n) p[i]=i;
		//random_shuffle(p,p+2*n);
		//rep(i,0,2*n) rk[p[i]]=i;
		los.clear();
		rep(i,0,n) {
			if (query(2*i,2*i+1)) {
				los.pb(2*i);
			} else {
				los.pb(2*i+1);
			}
		}
		sort(all(los),query);
		VI cc; dd.clear();
		rep(i,0,n-1) cc.pb(los[i]),cc.pb(los[i]^1);
		sort(all(cc),query);
		reverse(all(cc));
		dd.clear(); dd.pb(los[n-1]^1);
		rep(i,0,n-2) dd.pb(cc[i]);
		if (query(los[n-1],cc[n-2])) dd.pb(cc[n-2]);
		else dd.pb(los[n-1]);
		finished();
	}
}