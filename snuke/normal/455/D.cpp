#include<cstdio>
#include<algorithm>
#include<deque>
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

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

const int D = 800;
const int E = MX/D+5;
//const int E = 100;

deque<int> d[E];
int c[E][MX];

int main(){
	int n;
	scanf("%d",&n);
	rep(i,n) {
		int a;
		scanf("%d",&a);
		int pa = i/D;
		d[pa].pb(a);
		c[pa][a]++;
	}
	int q, last = 0;
	scanf("%d",&q);
	rep(qi,q) {
		int ty, l, r;
		scanf("%d%d%d",&ty,&l,&r);
		l = (l+last-1)%n;
		r = (r+last-1)%n;
		if (l > r) swap(l,r);
		if (ty == 1) {
			int la = l/D, lb = l%D;
			int ra = r/D, rb = r%D;
			if (la == ra) {
				int x = d[ra][rb];
				d[ra].erase(d[ra].begin()+rb);
				d[la].insert(d[la].begin()+lb,x);
			} else {
				int x = d[ra][rb];
				d[ra].erase(d[ra].begin()+rb);
				c[ra][x]--;
				for(int j = ra; j != la; --j) {
					int y = d[j-1].back();
					d[j].push_front(y);
					c[j][y]++;
					c[j-1][y]--;
					d[j-1].pop_back();
				}
				d[la].insert(d[la].begin()+lb,x);
				c[la][x]++;
			}
		} else {
			int k;
			scanf("%d",&k);
			k = (k+last-1)%n+1;
			int la = l/D, lb = l%D;
			int ra = r/D, rb = r%D;
			last = 0;
			if (la == ra) {
				for (int j = lb; j <= rb; ++j) last += (d[la][j] == k);
			} else {
				for (int j = 0; j <= rb; ++j) last += (d[ra][j] == k);
				for(int j = ra-1; j != la; --j) {
					last += c[j][k];
				}
				for (int j = lb; j < D; ++j) last += (d[la][j] == k);
			}
			printf("%d\n",last);
		}
	}
	
	return 0;
}