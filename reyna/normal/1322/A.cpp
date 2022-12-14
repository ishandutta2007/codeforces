
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
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int res = 0, cnt = 0;
	for (auto c : s) cnt += (c == '('), cnt -= (c == ')');
	if (cnt != 0) {
		cout << -1 << endl;
		return 0;
	}
	for (auto c : s) {
		if (cnt == 0 && c == ')') res++;
		cnt += (c == '(');
		cnt -= (c == ')');
		if (cnt < 0) ++res;
	}
	cout << res << endl;
	
}