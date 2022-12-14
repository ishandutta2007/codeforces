
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

int main() {
	string s;
	cin >> s;
	if (s == "0") {
		cout << 0 << endl;
		return 0;
	}
	int n = (int) s.size();
	int res = (n + 1) / 2;
	if (n & 1) {
		int flag = 1;
		for (int j = 1; j < n; ++j)
			flag &= (s[j] - '0') ^ 1;
		res -= flag;
	}
	cout << res << endl;
	
	
}