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
#define N 411111
 
#define TASK "1"
 
using namespace std;

set<pair<int, int> > buck;
map<int, int> cur;
map<int, vector<int> > pos;

void change(int val, int d) {
		pair<int, int> key = {cur[val], val};
		if (buck.find(key) != buck.end()) buck.erase(key);
		cur[val] += d;
		key = {cur[val], val};
		buck.insert(key);
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans[n];
	buck.clear();
	cur.clear();
	pos.clear();

	for (int i = 0; i < n; i++) pos[a[i]].push_back(i);
	for (int i = 0; i < n; i++) change(a[i], +1);
	auto it = buck.end();
	it--;
	int val = it->second;
	int start = val;
	change(val, -1);
	for (int q = n; q > 1; q--) {
		it = buck.end();
		it--;
		if (it->second == val && it != buck.begin()) {
			it--;
			if ((it -> first) == 0) it++;
		}
		int v2 = it->second;
		change(v2, -1);


		ans[pos[val].back()] = v2;
		pos[val].pop_back();
		val = v2;
	}
	ans[pos[val].back()] = start;
	for (int i = 0; i < n; i++) cout  << ans[i] << " ";
	cout << endl;
}
 
int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
		
	return 0;
}