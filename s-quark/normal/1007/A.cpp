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

int a[MAXN];

namespace MyCode {
int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n;
	int i, j;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);

	i = 0;
	j = 1;
	while(j < n){
		if(a[i] < a[j])
			i++;
		j++;
	}
	printf("%d\n", i);
	return 0;
}
}

int main(){
	return MyCode::main();
}