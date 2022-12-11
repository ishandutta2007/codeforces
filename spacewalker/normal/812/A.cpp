#include <cstdio>
#include <vector>

using namespace std;

inline int MOD(int n, int q) {
	return n % q + (n % q < 0 ? q : 0);
}

bool thereIsOne(vector<int> &v) {
	for (int i : v) {
		if (i == 1) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<vector<int>> reachable(4, vector<int>());
	vector<int> ped(4, 0);
	for (int i = 0; i < 4; ++i) {
		int l, s, r, p; scanf("%d %d %d %d", &l, &s, &r, &p);
		ped[i] = p;
		reachable[i].push_back(l);
		reachable[i].push_back(r);
		reachable[i].push_back(s);
		reachable[MOD(i - 1, 4)].push_back(l);
		reachable[MOD(i - 2, 4)].push_back(s);
		reachable[MOD(i - 3, 4)].push_back(r);
	}
	bool accident = false;
	for (int i = 0; i < 4; ++i) {
		if (ped[i] == 1 && thereIsOne(reachable[i])) {
			accident = true;
		}
	}

	printf("%s", (accident ? "YES" : "NO"));
	return 0;
}