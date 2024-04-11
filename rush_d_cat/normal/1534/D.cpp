#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n;
set< pair<int,int> > edges;
vector<int> ask(int u) {
	cout << "? " << u << endl;
	vector<int> r(n + 1, -1);
	for (int i = 1; i <= n; i ++) {
		cin >> r[i];
		if (r[i] == 1) edges.insert({min(u,i),max(u,i)});
	}
	return r;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> n;
	vector<int> r = ask(1);
	int c[2] = {0}; 
	for (int i = 1; i <= n; i ++) if (r[i] > 0) c[r[i]%2] ++;
	//cout << c[0] << " " << c[1] << endl;
	for (int i = 1; i <= n; i ++) {
		if (r[i] > 0) if (c[r[i]%2] < c[(r[i]%2)^1] || (c[r[i]%2] == c[(r[i]%2)^1] && r[i]%2==0)) ask(i);
	}
	cout << "!" << endl;
	for (auto e: edges) cout << e.first << " " << e.second << endl;
}