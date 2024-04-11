#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <map>

using namespace std;

#define maxk 32

typedef long long ll;

int st[33] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14,13,1};

#define maxn 100500

int n;
bool used[maxn];

int pow(int n, int i) {
	int res = 0;
	while (n >= i)
		n /= i, ++res;
	return res;
}

int main() {
	//for (int it = 1; it <= 1000; ++it) {
	//printf("% 5d : ", it);
	scanf("%d", &n);
	//n = it;
	int res = st[1];
	int i = 2;
	int cnt = 0;
	while (i * i <= n) {
		if (used[i]) {
			++i;
			continue;
		}
		int cp = pow(n, i);
		for (int j = 1, nw = i; j <= cp; ++j, nw *= i) {
			if (n / nw >= nw) used[nw] = true;
			else --cnt;
		}
		res ^= st[cp];
		++i;
	}
	cnt += (n - i + 1);
	res ^= (cnt & 1);
	if (res) printf("Vasya\n");
	else printf("Petya\n");
	/*if (!res) printf("% 6d : Petya\n", it);
	}*/
	return 0;
}