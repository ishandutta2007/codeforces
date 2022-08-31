#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
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

const int MX = 5005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

// Mod int
const int mod = 1000000007;
struct mint{
	ll x;
	mint():x(0){}
	mint(ll x):x(x){}
	mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
	mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
	mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
	mint operator+(const mint& a)const{ return mint(*this) += a;}
	mint operator-(const mint& a)const{ return mint(*this) -= a;}
	mint operator*(const mint& a)const{ return mint(*this) *= a;}
};
//

// Suffix array
struct SA{
	string s;
	int n;
	vi id, rank, lcp;
	
	struct Comp{
		int k;
		const vi &rank;
		Comp(const int k, const vi &rank):k(k),rank(rank){}
		bool operator()(int i, int j){
			if(rank[i] != rank[j]) return rank[i] < rank[j];
			int ri = i + k < sz(rank) ? rank[i + k] : -1;
			int rj = j + k < sz(rank) ? rank[j + k] : -1;
			return ri < rj;
		}
	};
	
	void cons(){
		s += '$';
		n = s.size();
		id = rank = vi(n);
		vi tmp(n);
		rep(i,n) id[i] = i, rank[i] = s[i];
		for(int k = 1; k < n; k<<=1){
			Comp comp(k, rank);
			sort(rng(id),comp);
			tmp[id[0]] = 0;
			for(int i = 1; i < n; i++)
				tmp[id[i]] = tmp[id[i-1]] + comp(id[i-1],id[i]);
			rank = tmp;
		}
		cons_lcp();
	}
	void cons_lcp(){
		lcp = vi(n);
		int h = 0;
		rep(i,n-1){
			int j = id[rank[i]-1];
			if(h > 0) h--;
			for(; i+h < n && j+h < n && s[i+h] == s[j+h]; h++);
			lcp[rank[i]-1] = h;
		}
	}
};
//

int d[MX][MX];
mint p[MX][MX];
int r[MX][MX];

string s;

int main(){
	cin >> s;
	int n = s.size();
  SA sa; sa.s = s; sa.cons();
  // rep(i,n+1) printf("%d ",sa.id[i]); puts("");
  // rep(i,n+1) printf("%d ",sa.rank[i]); puts("");
  // rep(i,n+1) printf("%d ",sa.lcp[i]); puts("");

  rep(i,n+1) {
    int now = n+1;
    for (int j = i+1; j <= n; ++j) {
      now = min(now,sa.lcp[j-1]);
      r[sa.id[i]][sa.id[j]] = r[sa.id[j]][sa.id[i]] = now;
    }
  }
  rep(i,n)for(int j = i+1; j < n; ++j) {
    if (r[i][j] >= j-i) r[i][j] = 1;
    else {
      r[i][j] = (sa.rank[i] < sa.rank[j]);
    }
    if (j+(j-i) > n) r[i][j] = 0;
  }
  //rep(i,n){rep(j,n) printf("%d ",r[i][j]); puts("");}

  rep(i,n+1)rep(j,n+1) d[i][j] = MX;
  rep(i,n+1) d[i][0] = 1;
  rep(i,n+1) p[i][0] = 1;
  rrep(i,n-1) {
    if (s[i] == '0') continue;
    int j = i-1, nd = MX;
    mint np = 0;
    for (int k = i+1; k <= n; ++k) {
      mins(d[k][i],nd+1);
      p[k][i] += np;
      if (j >= 0) {
        if (r[j][i]) {
          mins(d[k][i],d[i][j]+1);
          p[k][i] += p[i][j];
        }
        mins(nd,d[i][j]);
        np += p[i][j];
      }
      --j;
    }
  }
  //rep(i,n){for(int j = i+1; j <= n; ++j) cout << p[j][i].x << " "; cout << endl;}

  mint ans = 0;
  rep(i,n) ans += p[n][i];
  cout << ans.x << endl;

  bool ok = false;
  ans = 0;
  int best = 1<<29;
  for(int i = n-1; i >= 0; --i) {
    if (d[n][i] < MX) {
      mint sum = 0;
      for(int j = i; j < n; ++j) sum = sum*2+(s[j]-'0');
      sum += d[n][i];
      if (n-i > 20) ans = sum;
      else if (best > sum.x) {
        best = sum.x;
        ans = sum;
      }
      ok = true;
    }
    if (n-i >= 20 && ok) break;
  }
  cout << ans.x << endl;
	
	return 0;
}