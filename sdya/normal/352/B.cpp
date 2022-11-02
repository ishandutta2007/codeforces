#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main() {
	map < int, vector < int > > M;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int value;
		scanf("%d", &value);
		M[value].push_back(i);
	}
	vector < pair < int, int > > res;
	for (map < int, vector < int > > :: iterator it = M.begin(); it != M.end(); ++it) {
		vector < int > current = it->second;
		int diff = (current.size() < 2 ? 0 : (current[1] - current[0]));
		for (int i = 1; i < current.size(); ++i) {
			if (current[i] - current[i - 1] != diff) {
				diff = -1;
			}
		}
		if (diff >= 0) {
			res.push_back(make_pair(it->first, diff));
		}
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d %d\n", res[i].first, res[i].second);
	}
	return 0;
}