
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 0, mod = (int) 0;
string s = "codeforces";
int cnt[10];
int main() {
	long long k;
	cin >> k;
	for (int j = 0; j < 10; ++j) ++cnt[j];
	while (true) {
		long long cur = 1;
		for (int j = 0; j < 10; ++j)
			cur *= cnt[j];
		if (cur >= k) {
			for (int j = 0; j < 10; ++j)
				while (cnt[j]--)
					cout << s[j];
			return 0;
		}
		int i = 0;
		for (int j = 0; j < 10; ++j)
			if (cnt[i] > cnt[j])
				i = j;
		++cnt[i];
	}
}