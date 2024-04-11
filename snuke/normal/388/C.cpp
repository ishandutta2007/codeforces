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
#include<complex>
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
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000000000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

vi x[105];

int main(){
	int n, m;
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&m);
		rep(j,m){
			int a;
			scanf("%d",&a);
			x[i].pb(a);
		}
	}
	vi d;
	int s = 0, t = 0;
	rep(i,n){
		m = x[i].size();
		rep(j,m/2) s += x[i][j], t += x[i][m-j-1];
		if(m&1) d.pb(x[i][m/2]);
	}
	
	sort(rng(d));
	reverse(rng(d));
	rep(i,d.size()){
		if(i&1) t += d[i];
		else s += d[i];
	}
	
	cout << s << " " << t << endl;
	
	return 0;
}