#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define it iterator
typedef set<pair<int, int> > sp;
vector<int> e[100010];
bool u[100010];
void dfs (int v) {
	if (u[v])
		return;
	u[v] = 1;
	forn (i, e[v].size())
		dfs(e[v][i]);
}
int x[100010], y[100010];
map<int, sp> w[2];
int main () {
	int n, k;
	cin >> n >> k;
	forn (i, k) {
		cin >> x[i] >> y[i];
		if (x[i] == 1 || y[i] == n)
			e[i].pb(k);
		if (x[i] == n || y[i] == 1)
			e[k + 1].pb(i);
		w[0][x[i]].insert(mp(y[i], i));
		w[1][y[i]].insert(mp(x[i], i));
	}
	forn (q, 2)
		for (map<int, sp>::it i = w[q].begin(); i != w[q].end(); ++i)
			for (sp::it j = i->sc.begin(); j != i->sc.end(); ++j) {
				sp::it f = w[q][i->fs + 1].lower_bound(mp(j->fs - 1, -1));
				if (f != w[q][i->fs + 1].end())
					if (q)
						e[j->sc].pb(f->sc);
					else
						e[f->sc].pb(j->sc);
		}
	dfs(k + 1);
	cout << (u[k] ? -1 : (2 * n - 2)) << endl;
	return 0;
}