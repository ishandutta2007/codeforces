#include <cstdio>
#include <algorithm>
#include <set>
#define F first
#define S second
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;
int main() {
	int n;
	scanf("%d", &n);
	int sa[n], ea[n], sb[n], eb[n];
	iiii why[n];
	for (int i = 0; i < n; ++i) scanf("%d %d %d %d", &sa[i], &ea[i], &sb[i], &eb[i]);
	for (int i = 0; i < n; ++i) why[i] = iiii(ii(sa[i], ea[i]), ii(sb[i], eb[i]));
	sort(why, why + n);
	set<iiii> no;
	set<ii> killme;
	for (int i = 0; i < n; ++i) {
		while (!no.empty() && no.begin() -> F.F < why[i].F.F) {
			killme.insert(no.begin() -> S);
			no.erase(no.begin());
		}
		no.insert(iiii(ii(why[i].F.S, why[i].F.F), why[i].S));
		auto x = killme.lower_bound(why[i].S);
		if (x != killme.end() && x -> F <= why[i].S.S) {
			printf("NO");
			return 0;
		} else if (x != killme.begin() && (--x) -> S >= why[i].S.F) {
			printf("NO");
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) why[i] = iiii(ii(sb[i], eb[i]), ii(sa[i], ea[i]));
	sort(why, why + n);
	no.clear();
	killme.clear();
	for (int i = 0; i < n; ++i) {
		while (!no.empty() && no.begin() -> F.F < why[i].F.F) {
			killme.insert(no.begin() -> S);
			no.erase(no.begin());
		}
		no.insert(iiii(ii(why[i].F.S, why[i].F.F), why[i].S));
		auto x = killme.lower_bound(why[i].S);
		if (x != killme.end() && x -> F <= why[i].S.S) {
			printf("NO");
			return 0;
		} else if (x != killme.begin() && (--x) -> S >= why[i].S.F) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}