#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const R PI = acos(-1);
const int MAXN = 1<<20;
const int P = 1e9+7;

char s[MAXN];

namespace MyCode {
int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	scanf("%s", s);
	n = unique(s, s+n) - s;
	n = (n/2) + (n%2) * (s[0] == '0');
	ll ans;
	if(n == 0)
		ans = 0;
	else
		ans = (n-1) * (ll)min(x, y) + y;
	printf("%I64d\n", ans);
	return 0;
}
}

int main(){
	return MyCode::main();
}