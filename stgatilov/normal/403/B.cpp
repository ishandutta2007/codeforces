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

const int SIZE = 5<<10;

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }

int n, m;
int arr[SIZE];
set<int> bad;
bool good(int p) { return bad.find(p) == bad.end(); }


int parr[32];
int pcnt[32];
int pk;
void Factorize(int num) {
	pk = 0;
	memset(pcnt, 0, sizeof(pcnt));

	for (int i = 2; i*i<=num; i++) {
		if (num % i != 0) continue;
		parr[pk] = i;
		while (num % i == 0) {
			num /= i;
			pcnt[pk]++;
		}
		pk++;
	}

	if (num > 1) {
		parr[pk] = num;
		pcnt[pk] = 1;
		pk++;
	}
}

int Score() {
	int res = 0;
	for (int i = 0; i<pk; i++) {
		if (good(parr[i]))
			res += pcnt[i];
		else
			res -= pcnt[i];
	}
	return res;
}

int gg[SIZE], sc[SIZE];

int res[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);
	for (int j = 0; j<m; j++) {
		int q;
		scanf("%d", &q);
		bad.insert(q);
	}

	int ans = 0;
	for (int i = 0; i<n; i++) {
		Factorize(arr[i]);
		ans += Score();
	}

	int g = arr[0];
	gg[0] = sc[0] = 0;
	for (int i = 1; i<=n; i++) {
		gg[i] = g;
		Factorize(g);
		sc[i] = Score();
		g = gcd(g, arr[i]);
	}

	int ttt = 0;
	for (int i = 1; i<=n; i++) {
		res[i] = min(res[i], i * sc[i]);
		for (int j = i+1; j<=n; j++)
			res[j] = min(res[j], res[i] + (j-i) * sc[j]);
		ttt = min(ttt, res[i]);
	}

	Eo(ans);
	Eo(ttt);
	printf("%d\n", ans - ttt);


	return 0;
}