#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int N;

struct Node {
	vi ch;
	int size;
	int ans;
};
vector<Node> nodes;
int rec(int at) {
	int s = 1;
	trav(x, nodes[at].ch)
		s += rec(x);
	nodes[at].size = s;
	return s;
}

void rec2(int at, int top) {
	trav(x, nodes[at].ch)
		rec2(x, top+1);
	nodes[at].ans = 2*top + (N - top - (nodes[at].size - 1));
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> N;
	nodes.resize(N);
	rep(i,0,N-1) {
		int par;
		cin >> par;
		--par;
		nodes[par].ch.push_back(i+1);
	}
	int s = rec(0);
	assert(s == N);
	rec2(0, 1);
	rep(i,0,N) {
		cout << nodes[i].ans/2;
		cout << '.';
		cout << (nodes[i].ans%2 ? '5' : '0');
		cout << ' ';
	}
	cout << endl;
	exit(0);
}