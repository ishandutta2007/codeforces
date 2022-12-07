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
#define N 411111

#define TASK "1"

using namespace std;


map<pair<int, pair<int, int> >, int> was;

int f(int n, int type) {
	if (n == 0) return 1;
	int h = 0;

	if (was.find({n, {h, type}}) != was.end()) return was[{n, {h, type}}];

	int ans = 0;
	for (int i = (n - 1) / 2; i <= (n) / 2; i++) {
		if (type == 1 && (i % 2) == 0) continue;
		if (type == 0 && (n - 1 - i) % 2) continue;
		int l = 0;
		int r = 0;

		l = f(i, 0);
		r = f(n - i - 1, 1);

		ans = (ans + l * 1ll * r) % 998244353;
	}
	return was[{n, {h, type}}] = ans;
}                       
int solve(int n) {
	int ans = f(n, 2);
	return ans;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
//	for (int i = 1; i <= 1000; i++) cout << solve(i) << ',';
	cout << solve(n) << endl;
	return 0;
}