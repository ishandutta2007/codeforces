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
typedef pair<string,string> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

char c[55];
P s[MX], t[MX];

int main(){
	int n;
	scanf("%d",&n);
	rep(i,n) {
		scanf("%s",c);
		s[i].fi = c;
		scanf("%s",c);
		s[i].se = c;
	}
	rep(i,n) {
		int a;
		scanf("%d",&a);
		--a;
		t[i] = s[a];
	}
	string dp = "";
	rep(i,n){
		string a, b;
		a = t[i].fi; b = t[i].se;
		if (a > b) swap(a,b);
		if (dp < a) dp = a;
		else if (dp < b) dp = b;
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	
	return 0;
}