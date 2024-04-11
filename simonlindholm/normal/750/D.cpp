#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	set<pii> seen;
	set<pair<pii, int>> positions;
	positions.insert(make_pair(pii(0,0), 0));
	rep(i,0,N) {
		set<pair<pii, int>> positions2;
		int t;
		cin >> t;
		int DX[] = {1,1,0,-1,-1,-1,0,1};
		int DY[] = {0,1,1,1,0,-1,-1,-1};
		trav(pa, positions) {
			pii p = pa.first;
			int dir = pa.second;
			rep(j,0,t) {
				p.first += DX[dir];
				p.second += DY[dir];
				seen.insert(p);
			}
			int dir1 = (dir + 1) & 7;
			int dir2 = (dir - 1) & 7;
			positions2.insert(make_pair(p, dir1));
			positions2.insert(make_pair(p, dir2));
		}
		positions = move(positions2);
	}
	cout << seen.size() << endl;
	exit(0);
}