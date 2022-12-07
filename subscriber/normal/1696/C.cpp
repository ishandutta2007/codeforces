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

vector<pair<int, int> > dec(vector<int> a, int m) {
	vector<pair<int, int> > ret;
	for (int x : a) {
		int t = x;
		int c = 1;
		while (t % m == 0) {
			t /= m;
			c *= m;
		}
		ret.push_back({t, c});
	}
	return ret;
}

int check(vector<pair<int, int> > a, vector<pair<int, int> > b) {
	int p = 0;
	for (auto pa : a) {
		int x = pa.first;
		int cnt = pa.second;
		while (cnt > 0) {
			if (p < b.size() && b[p].second == 0) p++;
			if (p == b.size()) return 0;
			if (b[p].first != x) return 0;
			int l = min(cnt, b[p].second);

			cnt -= l;
			b[p].second -= l;
		}
	}
	if (p < b.size() && b[p].second == 0) p++;
	return p == b.size();
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
		int n, m, k;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> k;
		vector<int> b(k);
		for (int i = 0; i < k; i++) cin >> b[i];

		auto aa = dec(a, m);
		auto bb = dec(b, m);

		int ans = check(aa, bb);
		cout << (ans == 1 ? "Yes" : "No")  << endl;
	}
	return 0;
}