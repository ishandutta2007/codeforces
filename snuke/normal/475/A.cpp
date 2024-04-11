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

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int a[11][4];

int main(){
	int n;
	cin >> n;
	rep(i,11)rep(j,4) {
		if (n == 0) break;
		if (i && j == 2) continue;
		a[i][j] = 1;
		n--;
	}
	vector<string> s;
	s.pb("+------------------------+");
	s.pb("|#.#.#.#.#.#.#.#.#.#.#.|D|)");
	s.pb("|#.#.#.#.#.#.#.#.#.#.#.|.|");
	s.pb("|#.......................|");
	s.pb("|#.#.#.#.#.#.#.#.#.#.#.|.|)");
	s.pb("+------------------------+");
	rep(i,11)rep(j,4) {
		if (a[i][j]) {
			s[j+1][i*2+1] = 'O';
		}
	}
	rep(i,s.size()) cout << s[i] << endl;
	
	return 0;
}