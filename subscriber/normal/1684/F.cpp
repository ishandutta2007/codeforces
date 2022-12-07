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

int n, m;
int a[N];
int go[N];
int l[N], r[N];
vector<int> ev[N], ev2[N];
 
int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	int ts;
	cin >> ts;
	while (ts--) {
		cin >> n >> m;
		vector<pair<int, int> > e;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			e.push_back({a[i], i});
		}
		for (int i = 0; i < m; i++) {
			cin >> l[i]  >> r[i];
			l[i]--;
			r[i]--;
		}	
		for (int i = 0; i < n; i++) ev[i].clear(), ev2[i].clear();
		for (int i = 0; i < m; i++) {
			ev[l[i]].push_back(r[i]);
		}
		int so = -1;
		for (int i = 0; i < n; i++) {
			for (int x : ev[i]) so = max(so, x);
			if (so < i) go[i] = -1; else go[i] = so;
		}

		sort(e.begin(), e.end());

		int A = n;
		int B = -1;
		multiset<int> taking;

		for (int i = 0; i <e.size(); ) {
			int j = i;
			vector<int> pos;

			while  (j < e.size() && e[i].first == e[j].first) pos.push_back(e[j++].second);


			vector<pair<int, int> > segs;

			int last = -1;
			for (int k = 0; k < pos.size(); k++) {
				int p = pos[k];
				if (go[p] == -1) continue;

				int h = upper_bound(pos.begin(), pos.end(), go[p]) - pos.begin() - 1;
				if (h <= k || h == last) continue;
				last = h;
				segs.push_back({k, h});
			}
/*			cout << "segs for " << e[i].first << endl;
			for (int t : pos) cout << t << " ";
			cout << endl;
			cout << "segs" << endl;
			for (auto p : segs) cout << pos[p.first] << " " << pos[p.second] << endl;*/

			if (segs.size() > 1) {
				A = min(A, pos[segs[0].first + 1]);
				B = max(B, pos[segs.back().second - 1]);
			} else if (segs.size() == 1) {
//				if (segs[0].first + 1 != segs[0].second) {
					A = min(A, pos[segs[0].first + 1]);
					B = max(B, pos[segs[0].second - 1]);
//				}
				taking.insert(pos[segs[0].first]);
				ev2[pos[segs[0].first] + 1].push_back(pos[segs[0].second]);
			}
			i = j;
		}
		if (B == -1 && taking.size() == 0) {
			cout << 0 << endl;
			continue;
		}
		int ans = n;
		for (int i = 0; i <= A; i++) {
			int have = B;
			for (int x : ev2[i]) {
				taking.erase(taking.find(i - 1));
				taking.insert(x);
			}
			if (taking.size() > 0) {
				have = max(have, *prev(taking.end()));
//				cout << "upd " << have << endl;
			}
			if (i > have) break;
			ans = min(ans, have - i + 1);
		}
		cout << ans << endl;
	}		
	return 0;
}