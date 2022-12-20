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
const int MAXN = 1123;
const int P = 1e9+7;

bool f[MAXN*50];
const int v[] = {4, 9, 49};

namespace MyCode {
int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	if(n <= 10){
		int i, j;
		f[0] = true;
		for(i = 0; i < n; i++)
			for(j = n*49; j >= 0; j--)
				for(int k : v)
					if(j >= k)
						f[j] |= f[j-k];
		int ans = 0;
		for(j = 0; j <= 49*n; j++)
			ans += f[j];
		printf("%d\n", ans);
	}
	else{
		printf("%I64d\n", 49LL * n - 247);
	}
	return 0;
}
}

int main(){
	return MyCode::main();
}