#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e6 + 100;

int n;
double p;

double a[N], b[N];

bool check(double x) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double balance = b[i] - a[i] * x;
		sum += max(0.0, -balance);
	}
	return sum <= p * x;
}

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
    	int a, b; scanf("%d%d", &a, &b);
    	::a[i] = a;
    	::b[i] = b;
    }
    double l = 0, r = 1e12;
    for (int it = 0; it < 100; it++) {
    	double m = (l + r) / 2;
    	if (check(m)) {
    		l = m;
    	} else {
    		r = m;
    	}
    }
    if ((l + r) / 2 >= 1e11) {
    	printf("-1\n");
    } else {
    	printf("%.20lf\n", (l + r) / 2);
    }
    return 0;
}