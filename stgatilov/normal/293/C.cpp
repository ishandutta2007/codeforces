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

int64 n;
vector<int64> divs;

const int64 MAXN = 110000000000000LL;
const int64 MAXP = MAXN/6;
const int MAXA = int(sqrt(0.0+MAXN/6));

int64 func(int a, int b, int c) {
	int64 ans = 6LL*a*b*c;
	ans += 3LL*(a+b)*a*b;
	ans += 3LL*(a+c)*a*c;
	ans += 3LL*(b+c)*b*c;
	return ans;
}

bool Solve(int a, int b, int &c) {
	int x = (a+b);
	int64 y = int64(a)*b - n/(3*(a+b));
	int64 d = int64(x)*x - 4*y;
	if (d < 0) return false;
	double t = (sqrt(double(d)) - x) / 2.0;
	if (t < -0.5) return false;
	c = int(t+0.5);
	if (c < b) return false;
	return (func(a, b, c) == n);
}

int64 ans;


int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%I64d", &n);

	for (int i = 1; int64(i)*i<=n; i++) if (n % i == 0) {
		int64 oth = n/i;
		divs.push_back(i);
		if (oth != i) divs.push_back(oth);
	}
	std::sort(divs.begin(), divs.end());
	Eo(divs.size());

	int k = 0;
	int maxa = int(pow(n / 24.0, 1.0 / 3.0)) + 5;
	int maxb = int(pow(n / 6.0, 1.0 / 3.0)) + 5;
	while (k<divs.size() && divs[k] <= maxa+maxb) k++;
//	Eo(k);

	for (int i = 0; i<k; i++) {
//		Eo(i);
		int sab = divs[i];
		if ((n / sab) % 3) continue;
		for (int a = 1; a <= sab; a++) {
			if (a > maxa) break;
			int b = sab - a;
			if (b < a) break;
//			Eo(poss[TMP+b-a]);

			int c;
			if (Solve(a, b, c)) {
//				printf("%d %d %d\n", a, b, c);
				int r = (a==b) + (b==c) + (a==c);
				ans += (r==0 ? 6 : r==1 ? 3 : 1);
			}
//			ans++;
		}
	}


	printf("%I64d\n", ans);

	return 0;
}