#include <set>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int H, W; string s[555];
int main() {
	cin >> H >> W;
	set<string> z;
	for (int i = 0; i < H; i++) cin >> s[i], z.insert(s[i]);
	string t = string(W, '.');
	if (z.count(t)) z.erase(t);
	cout << (z.size() == 1 ? "YES" : "NO") << endl;
	return 0;
}