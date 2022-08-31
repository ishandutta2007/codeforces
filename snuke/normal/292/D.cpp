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
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 505, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

P e[10005];
int l[MX], li;
int r[MX], ri;

// Union find
struct uf{
	vector<int> par, rank;
	uf(){}
	uf(int sz){ par.resize(sz); rank.resize(sz); init(sz);}
	void init(int sz){ rep(i,sz) par[i] = i, rank[i] = 1;}
	int pa(int x){
		if(par[x] == x) return x;
		return par[x] = pa(par[x]);
	}
	void uni(int x, int y){
		x = pa(x); y = pa(y);
		if(rank[x] < rank[y]) swap(x,y);
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
};
//


int main(){
	int n, m, a, b, q, x, y, c, j;
	scanf("%d%d",&n,&m);
	
	rep(i,m){
		scanf("%d%d",&a,&b); a--; b--;
		e[i] = P(a,b);
	}
	
	uf t(MX);
	rep(i,m){
		a = e[i].fi; b = e[i].se;
		if(t.pa(a) != t.pa(b)){
			l[li++] = i;
			t.uni(a,b);
		}
	}
	
	t.init(MX);
	drep(i,m){
		a = e[i].fi; b = e[i].se;
		if(t.pa(a) != t.pa(b)){
			r[ri++] = i;
			t.uni(a,b);
		}
	}
	//rep(i,li) cout << l[i] << " "; cout << endl;
	//rep(i,ri) cout << r[i] << " "; cout << endl;
	
	scanf("%d",&q);
	
	rep(i,q){
		scanf("%d%d",&x,&y); x--; y--;
		t.init(MX); c = n;
		rep(i,li){
			j = l[i]; if(j >= x) break;
			a = e[j].fi; b = e[j].se;
			if(t.pa(a) != t.pa(b)){ t.uni(a,b); c--;}
		}
		rep(i,ri){
			j = r[i]; if(j <= y) break;
			a = e[j].fi; b = e[j].se;
			if(t.pa(a) != t.pa(b)){ t.uni(a,b); c--;}
		}
		printf("%d\n",c);
	}
	
	return 0;
}