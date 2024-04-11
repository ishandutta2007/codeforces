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
	int N, K;
	cin >> N >> K;
	int time = 60*4 - K;
	int solved = 0;
	while (solved < N && (solved+1) * 5 <= time) {
		solved++;
		time -= solved * 5;
	}
	cout << solved << endl;
	exit(0);
}