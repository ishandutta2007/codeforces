#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

vi seq;
vvi p;
queue<int> q;
bool ok = 1;
int curr = 1;
set<int> che;

void BFS(int ind) {
	che.insert(ind);
	vi so;
	vi uso;
	rep(i, 0, p[ind].size()) {
		if (!che.count(p[ind][i])) {
			uso.push_back(p[ind][i]);
		}
	}
	rep(i, curr, curr + uso.size()) {
		q.push(seq[i]-1);
		so.push_back(seq[i]-1);
	}
	curr += uso.size();

	sort(all(uso));
	sort(all(so));
	if (so != uso) {

		ok = 0;
	}
}

int main() {
	int n; cin >> n;
	seq.resize(n);
	p.resize(n);
	rep(i, 0, n - 1) {
		int x, y; cin >> x >> y;
		x--; y--;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	rep(i, 0, n) {
		cin >> seq[i];
	}
	q.push(0);
	while (!q.empty() && ok) {
		BFS(q.front());
		q.pop();
	}
	cout << (ok ? "Yes" : "No") << endl;
}