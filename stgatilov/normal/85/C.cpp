#pragma comment(linker, "/STACK:10000000")
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

const int SIZE = (1<<17);

int n, k, root;
int key[SIZE];
int father[SIZE];
int tleft[SIZE];
int tright[SIZE];

int mostleft[SIZE];
int mostright[SIZE];
double avg[SIZE];

map<int, int> dict;

void DFS1(int u) {
	mostleft[u] = key[u];
	mostright[u] = key[u];
	if (tleft[u] < 0) return;
    DFS1(tleft[u]);
    DFS1(tright[u]);
    mostleft[u] = min(mostleft[u], mostleft[tleft[u]]);
    mostright[u] = max(mostright[u], mostright[tright[u]]);
}

void DFS2(int u, double s, int h) {
//	printf("%d %0.5lf %d\n", u, s, h);
	if (tleft[u] < 0) {
		avg[u] = s / h;
		return;
	}
    DFS2(tleft[u], s + mostleft[tright[u]], h + 1);
    DFS2(tright[u], s + mostright[tleft[u]], h + 1);
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d%d", &father[i], &key[i]);
		if (father[i] > 0) father[i]--;
	}

	memset(tleft, -1, sizeof(tleft));
	memset(tright, -1, sizeof(tright));
	for (int i = 0; i<n; i++) {
		dict[key[i]] = i;
		if (father[i] < 0) root = i;
		else {
			int f = father[i];
			if (key[i] < key[f]) tleft[f] = i;
			else tright[f] = i;
		}
	}

	DFS1(root);
	DFS2(root, 0, 0);

//	for (int i = 0; i<n; i++) printf("%c %d [%d %d] %0.5lf\n", (tleft[i] < 0 ? 'L' : 'N'), key[i], mostleft[i], mostright[i], avg[i]);

	scanf("%d", &k);
	for (int i = 0; i<k; i++) {
		int x;
		scanf("%d", &x);
		double ans;

		typedef map<int, int>::iterator mIter;
		mIter it = dict.lower_bound(x);

		if (it == dict.begin())
			ans = avg[it->second];
		else if (it == dict.end()) {
			it--;
			ans = avg[it->second];
		}
		else {
			int ri = it->second;
			mIter pit = it;
			pit--;
			int li = pit->second;

			int ind = (tleft[li] < 0 ? li : ri);
            ans = avg[ind];
		}

		printf("%0.12lf\n", ans);
	}

	return 0;
}