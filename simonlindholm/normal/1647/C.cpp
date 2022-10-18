#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void run() {
	int N, M;
	cin >> N >> M;
	vector<string> grid(N);
	rep(i,0,N) cin >> grid[i];
	vector<tuple<int, int, int, int>> out;
	for (int i = N-1; i >= 0; i--)
		for (int j = M-1; j >= 0; j--) {
			if (grid[i][j] == '0') out.push_back({i+1,j+1,i+1,j+1});
			else if (i > 0) out.push_back({i, j+1, i+1, j+1});
			else if (j > 0) out.push_back({i+1, j, i+1, j+1});
			else {
				cout << -1 << endl;
				return;
			}
		}
	cout << sz(out) << endl;
	trav(pa, out) {
		int a,b,c,d;
		tie(a,b,c,d) = pa;
		cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	rep(i,0,N) run();
}