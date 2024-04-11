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

set<int> check;
int counter = 0;
vi v;
vvi p;
int m;
void dfs(int cats,int index) {
	check.insert(index);
	if (v[index] == 1) {
		cats++;
	}
	else {
		cats = 0;
	}
	if (cats > m) {
		return;
	}
	if (p[index].size() == 1&&index != 0) {
		counter++;
		return;
	}
	rep(i, 0, p[index].size()) {
		if (!check.count(p[index][i])) {
			dfs(cats, p[index][i]);
		}
	}
	return;

}


int main() {
	int n; cin >> n >> m;

	v.resize(n);
	rep(i, 0, n) {
		cin >> v[i];
	}

	p.resize(n);
	rep(i, 0, n - 1) {
		int x, y; cin >> x >> y;
		x--;
		y--;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(0, 0);
	cout << counter << endl;
}