#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 200100;
const long long ODDINF = 1LL + (long long)1e15;

vector<int> e[N];
int a[N];
long long odd[N], even[N];

void dfs(int v) {
	long long mxo = -ODDINF;
	long long mxe = 0;
	for (const int & to : e[v]) {
		dfs(to);
		long long oldmxo = mxo;
		mxo = max(mxo + even[to], mxe + odd[to]);
		mxe = max(mxe + even[to], oldmxo + odd[to]);
	}
	odd[v] = max(mxo, a[v] + mxe);
	even[v] = mxe;
}

int main() {
	int n, root;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p >> a[i];
		if (p == -1) {
			root = i;
		} else {
			e[p - 1].push_back(i);
		}
	}
	dfs(root);
	cout << max(odd[root], even[root]) << endl;
	return 0;
}