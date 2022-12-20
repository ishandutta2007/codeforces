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
#include <cstdint>
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

namespace MyCode {
int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	ll x1, x2, x3, y1, y2, y3;
	ll n;

	x1 = x2 = y1 = y2 = 1;
	cin>>n;
	x3 = y3 = n+1;

	for(int cnt = 0; cnt < 600; cnt++){
		ll x = (x2+x3) / 2;
		ll y = (y2+y3) / 2;
		if((R)(x2-x1) * (y3-y2) >= (R)(x3-x2) * (y3-y1))
			x = x2;
		if((R)(y2-y1) * (x3-x2) >= (R)(y3-y2) * (x3-x1))
			y = y2;
		cout << n+1-x << " " << n+1-y << endl;
		int res;
		scanf("%d", &res);
		if(res == 0)
			exit(0);
		if(res == 1)
			x3 = x;
		if(res == 2)
			y3 = y;
		if(res == 3)
			x2 = x+1, y2 = y+1;

		if(x2 == x3)
			y1 = y2, x2 = x1;
		if(y2 == y3)
			x1 = x2, y2 = y1;
	}
	return 0;
}
}

int main(){
	return MyCode::main();
}