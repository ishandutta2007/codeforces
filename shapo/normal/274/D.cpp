#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <deque>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define fill(a,x) memset(a,x,sizeof(a))
#define forn(i,a,b) for(int i = (a); i < (b); ++i)

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

#define maxn 100500

int cnt[maxn];
vpii sm[maxn];
vi arr[maxn];
int n, m;
deque < int > cur;
vi ans;
int pos[maxn], num[maxn];

int main() {
	scanf("%d%d", &n, &m);
	forn(i, 0, n) {
		forn(j, 0, m) {
			int a;
			scanf("%d", &a);
			arr[i].pb(a);
			if (a == -1)
				++cnt[j];
			else
				sm[i].pb(mp(a, j));
		}
		sort(sm[i].begin(), sm[i].end());
	}
	forn(i, 0, n) {
		pos[i] = 0;
		int r = pos[i];
		while (r < sz(sm[i]) && sm[i][pos[i]].first == sm[i][r].first)
			++cnt[sm[i][r].second], ++r, ++num[i];
		pos[i] = r;
	}
	forn(i, 0, m)
		if (cnt[i] == n) cur.pb(i);
	while (!cur.empty()) {
		int to = cur.front();
		cur.pop_front();
		ans.pb(to + 1);
		forn(i, 0, n) {
			if (arr[i][to] != -1) --num[i];
			if (!num[i]){
				int r = pos[i];
				while (r < sz(sm[i]) && sm[i][r].first == sm[i][pos[i]].first) {
					int mygom = sm[i][r].second;
					++cnt[mygom];
					if (cnt[mygom] == n) cur.pb(mygom);
					++r;
					++num[i];
				}
				pos[i] = r;
			}
		}
	}
	forn(i, 0, n)
		if (pos[i] != sz(sm[i]) || sz(ans) != m) {
			printf("-1\n");
			return 0;
		}
	for (int i = 0; i < m; ++i)
		printf("%d ", ans[i]);
	return 0;
}