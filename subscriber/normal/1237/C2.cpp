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

int cur;
bool my(vector<int> o1, vector<int> o2) {
	return o1[cur] < o2[cur];
}

vector<vector<int> > solve(vector<vector<int> > a, int t) {
	if (t == 3) return a;

//	cout << "check " << t << " " << a.size() << endl;

	cur = t;
	sort(a.begin(), a.end(), &my);

	vector<vector<int> > rest;
	for (int i = 0; i < a.size(); i++) {
		int j = i;

		vector<vector<int> > q;
		while (j < a.size() && a[i][t] == a[j][t]) {
			q.pb(a[j]);
			j++;
		}
		i = j - 1;
		q = solve(q, t + 1);
		for (auto x : q) rest.pb(x);
	}
	while (rest.size() >= 2) {
		cout << rest.back().back() + 1 << " " << rest[rest.size() - 2].back() + 1 << endl;
		rest.pop_back();
		rest.pop_back();
	}
	return rest;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int> > a(n);

	for (int i = 0; i < n; i++) {
		a[i] = vector<int>(4);
		for (int j = 0; j < 3; j++) cin >> a[i][j];
		a[i][3] = i;
	}

	solve(a, 0);
	return 0;
}