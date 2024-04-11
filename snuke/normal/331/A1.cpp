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
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)clock())
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<ll,int> Q;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int a[MX]; ll b[MX];
P p[MX];

vector<int> c;

int main(){
	int n;
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
		p[i] = P(a[i],i);
	}
	
	sort(p,p+n);
	
	rep(i,n) b[i] = max(0,a[i]);
	rrep(i,n) b[i] += b[i-1];
	
	int h, pre;
	Q ans = Q(-LINF,0);
	rep(i,n){
		h = a[i];
		pre = lower_bound(p,p+n,P(h,0))-p;
		if(p[pre].se == i) continue;
		int j = p[pre].se;
		ans = max(ans,Q(h*2+b[i-1]-b[j],i));
	}
	
	pre = lower_bound(p,p+n,P(a[ans.se],0))-p;
	int l = p[pre].se, r = ans.se;
	rep(i,l) c.pb(i);
	for(int i = l+1; i < r; i++) if(a[i] < 0) c.pb(i);
	for(int i = r+1; i < n; i++) c.pb(i);
	cout << ans.fi << " " << c.size() << endl;
	rep(i,c.size()) printf("%d%c",c[i]+1,i==c.size()-1?'\n':' ');
	
	return 0;
}