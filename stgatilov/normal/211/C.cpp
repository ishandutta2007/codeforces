//#pragma comment(linker, "/STACK:30000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;
typedef long long int64;
#define E(c) fprintf(stderr, #c)
#define Eo(c) std::cerr << #c << " = " << (c) << std::endl

const int SIZE = 128;

struct Long {
	vector<int> arr;

	Long(int x = 0) {
		if (x) arr.push_back(x);
	}
};

typedef Long Value;

int n;
char str[SIZE];
Value res[2][2][SIZE][2][2];

void Add(Value &a, const Value &b) {
	a.arr.resize(max(a.arr.size(), b.arr.size()));
	int buf = 0;
	for (int i = 0; i<a.arr.size() || i<b.arr.size(); i++) {
		int res = (i<a.arr.size() ? a.arr[i] : 0) + (i<b.arr.size() ? b.arr[i] : 0) + buf;
		if (res < 10) {
			a.arr[i] = res;
			buf = 0;
		}
		else {
			a.arr[i] = res - 10;
			buf = 1;
		}
	}
	if (buf) a.arr.push_back(buf);
}
void Print(const Value &a) {
	for (int i = a.arr.size() - 1; i>=0; i--)
		printf("%d", a.arr[i]);
	if (a.arr.empty()) printf("0");
	printf("\n");
}

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    scanf("%s\n", str);
    n = strlen(str);
	
	for (int l1 = 0; l1<2; l1++)
		for (int l2 = 0; l2<2; l2++)
			res[l1][l2][0][l1][l2] = 1;

	for (int s1 = 0; s1<2; s1++)
	for (int s2 = 0; s2<2; s2++)
		for (int i = 0; i<n; i++)
			for (int l1 = 0; l1<2; l1++)
			for (int l2 = 0; l2<2; l2++) {
				const Value &tres = res[s1][s2][i][l1][l2];
				int pi1 = (i-2+n) % n;
				int pi2 = (i-1+n) % n;

				if (!(l1==0 && l2==0 && str[pi1]=='A' && str[pi2]=='B'))
					Add(res[s1][s2][i+1][l2][0], tres);
				if (l2==0 && str[pi2] == 'B' && str[i] == 'A')
					Add(res[s1][s2][i+1][l2][1], tres);
			}

	Value ans = 0;
	for (int l1 = 0; l1<2; l1++)
	for (int l2 = 0; l2<2; l2++)
		Add(ans, res[l1][l2][n][l1][l2]);
	
	Print(ans);

	return 0;
}