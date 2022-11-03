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

int n;
int phi[1<<20];

int used[1<<20];
int level;

int curr;

vector<int> cnt;
vector<int> moves;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	memset(used, 0, sizeof(used));
	for (int i = 1; i<=n; i++) {
		level++;
		for (int k = 2; ; k++) {
			int mini = (k * (k+1)) >> 1;
			if (i < mini) break;

			if ((i<<1) % k) continue;
			int t = (i<<1) / k;

			t -= (k-1);
			if (t & 1) continue;
			int l = t / 2;

			int curr = 0;
			for (int j = 0; j<k; j++) curr ^= phi[l+j];
			used[curr] = level;

			if (i == n) {
				cnt.push_back(k);
				moves.push_back(curr);
			}
		}

		int j;
		for (j = 0; used[j] == level; j++);
		phi[i] = j;
	}

	if (phi[n] == 0) printf("-1\n");
	else {
		for (int i = 0; i<cnt.size(); i++) if (moves[i] == 0) {
			printf("%d\n", cnt[i]);
			break;
		}
	}

	return 0;
}