#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;

int n;
double ans[N];
int sz[N];
vector<int> v[N];

void calc(int x, int de) {
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		calc(v[x][i], de + 1);
		sz[x] += sz[v[x][i]];
	}
	ans[x] = 1 + de;
	int rest = n - sz[x] - de;
	ans[x] += rest / 2.;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		v[x].pb(i);
	}

	calc(1, 0);
	for (int i = 1; i <= n; i++) printf("%.2lf ", ans[i]);

	return 0;
}