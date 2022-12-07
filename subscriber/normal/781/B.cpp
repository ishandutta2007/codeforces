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

vector<int> q[26][26];
string a[N], b[N];

char ans[N];




int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];

		q[a[i][0] - 'A'][a[i][1] - 'A'].pb(i);
	}
	for (int x = 0; x < 26; x++) for (int y = 0; y < 26; y++) if (q[x][y].size() > 0) {
		if (q[x][y].size() > 26) {
			cout << "NO\n";
			return 0;
		}
		int k = q[x][y].size();
		int e[k];
		for (int i = 0; i < k; i++) e[i] = 0;

		for (int i = 0; i < k; i++) for (int j = 0; j < i; j++) if (a[q[x][y][i]][2] == a[q[x][y][j]][2]) {
			e[i] = 1;
			e[j] = 1;
		}
		set<char> was;

		for (int i = 0; i < k; i++) if (e[i]) {
			char t = b[q[x][y][i]][0];
			if (was.count(t)) {
				cout << "NO\n";
				return 0;
			}
			was.insert(t);
			ans[q[x][y][i]] = t;
		}
		int ch = 1;
		while (ch) {
			ch = 0;
			for (int i = 0; i < k; i++) if (!e[i]) {
				if (was.count(a[q[x][y][i]][2])) {
					char t = b[q[x][y][i]][0];
					if (was.count(t)) {
						cout << "NO\n";
						return 0;
					}
					e[i] = 1;
					was.insert(t);
					ans[q[x][y][i]] = t;
					ch = 1;
				}
			}
		}
		for (int i = 0; i < k; i++) if (!e[i]) ans[q[x][y][i]] = a[q[x][y][i]][2];
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) cout << a[i][0] << a[i][1] << ans[i] << endl;
	return 0;
}