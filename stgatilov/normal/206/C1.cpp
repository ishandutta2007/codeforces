#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 7200;
const int CHARS = 26;

int n;
int sz[2];
vector<int> next[2][SIZE][CHARS];
int father[2][SIZE];
int fchar[2][SIZE];
int64 ans = 1;

void DFS(int c1, int c2) {
	ans++;
	int n2 = father[1][c2];
	if (n2 < 0) return;
	int cc = fchar[1][c2];
	const vector<int> &v = next[0][c1][cc];
	for (int w = 0; w<v.size(); w++)
		DFS(v[w], n2);
}

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	memset(father, -1, sizeof(father));
	memset(fchar, -1, sizeof(fchar));

	sz[0] = sz[1] = 1;
	for (int i = 0; i<n; i++) {
		int t, v, c;
		char ch;
		scanf("%d%d %c", &t, &v, &ch);
		t--; v--;
		c = ch - 'a';

		int add = sz[t]++;
		next[t][v][c].push_back(add);
		father[t][add] = v;
		fchar[t][add] = c;

		if (t == 0) {
			string s;
			for (int curr = add; curr > 0; curr = father[0][curr])
				s += fchar[0][curr];
			reverse(s.begin(), s.end());
			
			for (int u = 0; u<sz[1]; u++) {
				int curr = u;
				for (int q = 0; q<s.size(); q++) {
					if (fchar[1][curr] != s[q]) {
						curr = -1;
						break;
					}
					curr = father[1][curr];
				}
				if (curr >= 0) ans++;
			}
		}
		else {
			int c2 = add;
			int c1 = 0;
			DFS(c1, c2);
		}

		printf("%d\n", ans);
	}



	return 0;
}