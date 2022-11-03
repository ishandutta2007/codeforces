//#pragma comment(linker, "/STACK:20000000")
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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 256;

int n;
int comp[SIZE];
vector<int> nbr[SIZE];
bool done[SIZE];
bool poss[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &comp[i]);
		comp[i]--;
	}
	for (int i = 0; i<n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j<k; j++) {
			int a;
			scanf("%d", &a);
			a--;
			nbr[i].push_back(a);
		}
	}

	int ans = 1000000000;
	for (int st = 0; st<3; st++) {
		int curr = st;
		int tans = 0;
		memset(done, 0, sizeof(done));

		while (1) {
			memset(poss, 0, sizeof(poss));
			bool alldone = true;
			for (int i = 0; i<n; i++) if (!done[i]) {
				alldone = false;
				bool ok = true;
				for (int j = 0; j<nbr[i].size(); j++) {
					int need = nbr[i][j];
					if (!done[need]) ok = false;
				}
				poss[i] = ok;
			}
			if (alldone) break;

			int doit = -1;
			for (int i = 0; i<n; i++) if (poss[i] && comp[i] == curr)
				doit = i;
			
			if (doit < 0) {
				tans++;
				curr = (curr + 1) % 3;
			}
			else {
				tans++;
				done[doit] = true;
			}
		}

		ans = min(ans, tans);
	}

	printf("%d", ans);
	return 0;
}