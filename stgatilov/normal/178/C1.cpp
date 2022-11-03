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

typedef pair<int, int> pii;

const int SIZE = 200<<10;

int h, m, n;

int k;
bool used[SIZE];
pii place[SIZE];
set<int> empty[SIZE];
map<int, pii> elems;

char buff[1024];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	gets(buff);
	sscanf(buff, "%d%d%d", &h, &m, &n);

	for (int i = 0; i<h; i++) {
		if (used[i]) continue;

		int qq = 0;
		int curr = i;
		do {
			used[curr] = true;
			place[curr] = pii(k, qq);
			empty[k].insert(qq);
			qq++;

			curr += m;
			curr %= h;
		} while (!used[curr]);

		k++;
	}

	int64 ans = 0;
	for (int i = 0; i<n; i++) {
		gets(buff);
		char ch;
		int id, hf;
		sscanf(buff, " %c%d%d", &ch, &id, &hf);

		if (ch == '+') {
			pii pl = place[hf];

			set<int>::iterator it;
			it = empty[pl.first].lower_bound(pl.second);
			if (it == empty[pl.first].end())
				it = empty[pl.first].begin();
			assert(it != empty[pl.first].end());

			int ind = *it;
			int addtoans = ind - pl.second;
			if (addtoans < 0) addtoans += h/k;
			ans += addtoans;

			empty[pl.first].erase(ind);
			elems[id] = pii(pl.first, ind);
//			Ef("%d %d->%d\n", pl.first, pl.second, ind);
			
		}
		else {
			pii pl = elems[id];
			elems.erase(id);

			empty[pl.first].insert(pl.second);
		}
	}

	printf("%I64d\n", ans);

	return 0;
}