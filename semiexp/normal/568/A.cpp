#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int p, q;
bool is_prime[5000010];

bool is_palindrome(int a)
{
	int seq[50], slast = 0;
	while (a) {
		seq[slast++] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < slast; ++i) if (seq[i] != seq[slast - 1 - i]) return false;
	return true;
}

int main()
{
	scanf("%d%d", &p, &q);
	int ret = 1;

	is_prime[1] = false;
	for (int i = 2; i <= 5000000; ++i) is_prime[i] = true;
	for (int i = 2; i <= 5000000; ++i) if (is_prime[i]) {
		if (i > 2000) continue;
		for (int j = i * i; j <= 5000000; j += i) is_prime[j] = false;
	}

	int pi = 0, rub = 0;
	for (int i = 1; i <= 5000000; ++i) {
		if (is_prime[i]) ++pi;
		if (is_palindrome(i)) ++rub;

		if ((i64)q * pi <= (i64)p * rub) ret = i;
	}
	printf("%d\n", ret);

	return 0;
}