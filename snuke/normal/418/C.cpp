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

const int MX = 105, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int x[MX], y[MX];
int r[MX], h[MX];

int main(){
	rrep(i,100)rrep(j,100)rep(k,100) {
		if (x[k] != 0) continue;
		int a = (i+j)*(i+j)-i*i-k;
		if (a > 0) {
			int s = (int)sqrt(a);
			if (s*s == a) {
				x[k] = i;
				y[k] = s;
			}
		}
	}
	//rep(i,100)printf("%d %d\n",x[i],y[i]);

	int n, m;
	cin >> n >> m;
	rep(i,n) r[i] = 1;
	rep(i,m) h[i] = 1;
	if (n >= 2) {
		int a = n-2;
		r[0] = x[a];
		r[1] = y[a];
	}
	if (m >= 2) {
		int a = m-2;
		h[0] = x[a];
		h[1] = y[a];
	}
	rep(i,n) {
		rep(j,m) printf("%d%c", r[i]*h[j], j==m-1?'\n':' ');
	}
	
	return 0;
}