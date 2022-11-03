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
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int k, t;
char matr[1024][1024];
const int N = 60;

bool win(int n, int m) {
	n++;
	m++;
	if (n==1 && m==1) return false;

	int k1 = k + 1;

	int dk = min(n, m) / k1;
	n -= dk * k1;
	m -= dk * k1;
	if (n==0 || m==0) return true;

	return (n+m + (k==1 ? 0 : dk)) % 2;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	scanf("%d", &k);
	for (int i = 0; i<t; i++) {
		int n, m;
		scanf("%d%d", &n, &m);
		n--; m--;
		printf("%c\n", (win(n, m) ? '+' : '-'));
	}
	return 0;
}