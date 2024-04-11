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

const int N = 1000;

int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	printf("%d\n", N*2+1);
	for(int i = 1; i <= N; i++)
		printf("%d %d %d %d\n", i, 1, i, 2);
	printf("%d %d %d %d\n", 1, 1, 2, 2);
	for(int i = 1; i <= N; i++)
		printf("%d %d %d %d\n", i, 1, i, 2);
	return 0;
}