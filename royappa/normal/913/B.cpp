#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<int> p(n+1);
	p[1] = 0;
	vector<int> notLeaf(n+1, 0);
	map<int,set<int>> children;
	for (int i = 1; i <= n-1; i++) {
		int x;
		cin >> x;
		p[i+1] = x;
		notLeaf[x] = 1;
		children[x].insert(i+1);
	}
	bool good = true;
	for (auto x : children) {
		int par = x.first;
		if (notLeaf[par]) {
			auto kids = x.second;
			int nlc = 0;
			for (auto c : kids) {
				if (!notLeaf[c]) {
					nlc++;
				}
			}
			if (nlc < 3) {
				good = false;
				break;
			}
		}
	}
	cout << (good ? "Yes" : "No") << endl;
	exit(0);
}