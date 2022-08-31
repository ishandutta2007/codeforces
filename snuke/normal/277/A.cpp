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

const int MX = 105, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const int dx[4] = {0,-1,1,0}, dy[4] = {-1,0,0,1};

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

int l[MX]; bool b[MX];

int main(){
	int n, m, k, ans = 0;
	scanf("%d%d",&n,&m);
	
	uf t(m+1);
	rrep(i,m) b[i] = false;
	rep(i,n){
		scanf("%d",&k);
		rep(j,k){
			scanf("%d",&l[j]);
			rep(h,j) t.uni(l[j],l[h]);
			b[l[j]] = true;
		}
		if(k == 0) ans++;
	}
	
	bool bl = false;
	rrep(i,m){
		if(b[i] && t.pa(i) == i){
			if(bl) ans++;
			bl = true;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}