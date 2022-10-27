#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int L, R;
vector< pair<int,int> > g[33];

int main() {
	cin >> L >> R;
	int B = 32;
	for (int i = B - 1; i >= 2; i --) {
		for (int j = B; j > i; j --) {
			if (j == B) {
				g[i].push_back(make_pair(j, 1));
			} else {
				g[i].push_back(make_pair(j, 1<<(B-j-1)));
			}
		}
	}
	int mask = R - L;
	g[1].push_back(make_pair(B, 1));
	int sum = 1;
	for (int i = 22; i >= 0; i --) {
		if (mask >> i & 1) {
			g[1].push_back(make_pair(B - i - 1, sum));
			sum += (1<<i);
		}
	}
	cout << "YES" << endl;
	vector< vector<int> > f;
	for (int i = 1; i <= B; i ++) {

		for (auto e: g[i]) 
			f.push_back({i, e.first, min(e.second + (i==1?L-1:0), 1000000)});

	}
	cout << 32 << " " << f.size() << endl;
	for (auto e: f) {
		cout << e[0] << " " << e[1] << " " << e[2] << endl;
	}
}