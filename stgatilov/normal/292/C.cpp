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

int Convert(int *arr, int k) {
	int q = 0;
	for (int t = 0; t<k; t++) {
		q *= 10;
		q += arr[t];
	}
	return q;
}

bool IsValid(int *arr, int k) {
	if (k < 1 || k > 3) return false;
	if (arr[0] == 0) return k == 1;
	int q = Convert(arr, k);
	return q>=0 && q<=255;
}

int k;
bool can[16];
vector<string> ans;

int len;
int digits[16];

int vals[4];

void RecX(int usl, int done) {
//	printf("[%d,%d]", usl, done);

	int rem = len - usl;
	int minv = (4-done)*1;
	int maxv = (4-done)*3;
	if (rem < minv || rem > maxv)
		return;
	
	if (done == 4) {
//		for (int i = 0; i<len; i++) printf("%d", digits[i]); printf("\n");
		char buff[256];
		sprintf(buff, "%d.%d.%d.%d", vals[0], vals[1], vals[2], vals[3]);
//		printf("%s\n", buff);
		ans.push_back(buff);
		return;
	}

	for (int i = 1; i<=3; i++) {
		if (usl + i > len) break;
        if (!IsValid(digits+usl, i)) continue;
        vals[done] = Convert(digits+usl, i);
        RecX(usl + i, done+1);
	}
}

bool used[16];
void Rec(int u) {
	if (2*u>=len) {
		for (int i = 0; i<10; i++) if (can[i] && !used[i])
			return;
		RecX(0, 0);
		return;
	}

	for (int d = 0; d<10; d++) if (can[d]) {
		digits[u] = digits[len-1-u] = d;
		bool ok = !used[d];
		if (ok) { used[d] = true; }
		Rec(u+1);
		if (ok) { used[d] = false; }
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &k);
	for (int i = 0; i<k; i++) {
		int d;
		scanf("%d", &d);
		can[d] = true;
	}

	for (len = 1; len<=12; len++) {
		Rec(0);
	}

	printf("%d\n", ans.size());
	for (int i = 0; i<ans.size(); i++)
		printf("%s\n", ans[i].c_str());
	
	return 0;
}