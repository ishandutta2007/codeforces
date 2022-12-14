
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

const int N = (int) 1e6 + 6, mod = (int) 0;
char res[N];
int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	for (int j = 0; j < n; ++j) res[j] = s[j];
	int cnt = 0;
	for (int j = n - 1; j >= 0; --j) {
		if (s[j] == '0') ++cnt;
		else {
			if (cnt > 0) --cnt;
			else res[j] = '0';
		}
	}
	string t = "";
	for (int j = 0; j < n; ++j) t += res[j];
	cout << t << endl;
}