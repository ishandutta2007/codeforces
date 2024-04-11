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

int was[N];
pair<int, int> q[N];
int n;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i <n; i++) {
		cin >> q[i].F;
		q[i].S = i;
	}
	sort(q, q + n);
	vector<vector<int> > ee;
	for (int i = 0; i < n; i++) if (!was[i]) {
		int x = i;
		vector<int> e;

		for(;;) {
			e.pb(x);
			was[x] = 1;
			x = q[x].S;
			if (was[x]) break;
		}
		ee.pb(e);
	}
	cout << ee.size() << endl;
	for (int i = 0; i < ee.size(); i++) {
		cout << ee[i].size() << " ";
		for (int j = 0; j < ee[i].size(); j++) cout << ee[i][j] + 1 << " ";
		cout << endl;
	}
	return 0;
}