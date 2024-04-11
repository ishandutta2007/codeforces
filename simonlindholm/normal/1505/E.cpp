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
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vector<string> grid(N);
	rep(i,0,N) cin >> grid[i];
	int ati = 0, atj = 0;
	int sum = 0;
	while (ati < N-1 || atj < M-1) {
		sum += grid[ati][atj] == '*';
		if (ati == N-1) {
			atj++;
		} else if (atj == M-1) {
			ati++;
		} else {
			for (int d = 1; d <= 10; d++) {
				if (atj + d < M && grid[ati][atj + d] == '*') { atj++; goto end; }
				if (ati + d < N && grid[ati + d][atj] == '*') { ati++; goto end; }
			}
			atj++;
end:;
		}
	}
	sum += grid[ati][atj] == '*';
	cout << sum << endl;
	exit(0);
}