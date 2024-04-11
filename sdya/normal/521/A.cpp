#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n;
string s;
const long long P = 1000000007LL;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> s;
	vector < int > cnt(4);
	cnt[0] = count(s.begin(), s.end(), 'A');
	cnt[1] = count(s.begin(), s.end(), 'C');
	cnt[2] = count(s.begin(), s.end(), 'G');
	cnt[3] = count(s.begin(), s.end(), 'T');

	int res = *max_element(cnt.begin(), cnt.end());
	int t = count(cnt.begin(), cnt.end(), res);
	long long r = 1;
	for (int i = 0; i < n; ++i) {
		r = (r * (long long)(t)) % P;
	}
	cout << r << endl;

	return 0;
}