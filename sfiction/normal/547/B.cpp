#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <utility>
#include <vector>

#define debug(x) cout << #x##" = " << x;

using namespace std;

const int MAXN = 2E5 + 100;

int n;
int a[MAXN];
int ans[MAXN];

set<pair<int, int> > lst;
set<int> loc;

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
		lst.insert(make_pair(a[i], i));
		loc.insert(i);
	}
	memset(ans, -1, sizeof(ans));

	for (set<pair<int, int> >::iterator p = lst.end(); p != lst.begin(); ){
		int t = (--p)->second;
//		printf("%d\n", t);
		set<int>::iterator mp = loc.find(t), lp = mp, rp = mp;
		int lc, rc;
		if (lp == loc.begin())
			lc = 0;
		else
			lc = *(--lp) + 1;
		if ((++rp) == loc.end())
			rc = n - 1;
		else
			rc = *rp - 1;
//		printf("mp: %d (%d, %d)\n", *mp, lc, rc);

		int len = rc - lc + 1;
		ans[len] = max(ans[len], a[*mp]);

		loc.erase(mp);
	}

	for (int i=n-1;i>=1;--i)
		ans[i] = max(ans[i], ans[i + 1]);

	printf("%d", ans[1]);
	for (int i=2;i<=n;++i)
		printf(" %d", ans[i]);

	return 0;
}