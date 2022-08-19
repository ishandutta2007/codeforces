#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 1005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int p, k;
int a[MX][MX];
ll r[MX], c[MX];
ll sr[MX*MX], sc[MX*MX];

void f(ll d[], int n, int m, ll s[]){
	priority_queue<ll> q;
	rep(i,n) q.push(d[i]);
	rep(i,k) {
		ll x = q.top(); q.pop();
		q.push(x-p*m);
		s[i+1] = s[i] + x;
	}
}

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&k,&p);
	rep(i,n)rep(j,m) scanf("%d",&a[i][j]);
	ll ans = -LINF;
	rep(i,n) {
		int sum = 0;
		rep(j,m) sum += a[i][j];
		r[i] = sum;
	}
	rep(i,m) {
		int sum = 0;
		rep(j,n) sum += a[j][i];
		c[i] = sum;
	}
	f(r,n,m,sr);
	f(c,m,n,sc);
	rep(i,k+1){
		ll now = -(ll)((ll)i*(k-i))*p;
		now += sr[i]+sc[k-i];
		ans = max(ans, now);
	}
	cout << ans << endl;
	
	return 0;
}