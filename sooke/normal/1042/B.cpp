#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

typedef long long lol;
typedef long double lod;

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807ll;

std::map<std::string, int> map;
int n, ans;

int main() {
	map["A"] = map["B"] = map["C"] = map["AB"] = map["AC"] = map["BC"] = map["ABC"] = maxInt / 10;
	n = read();
	for (int i = 1; i <= n; i++) {
		int val = read(); std::string s;
		std::cin >> s;
		if (s == "BA") { s = "AB"; }
		if (s == "CA") { s = "AC"; }
		if (s == "CB") { s = "BC"; }
		if (s.size() == 3) { s = "ABC"; }
		map[s] = std::min(map[s], val);
	}
	ans = map["ABC"];
	ans = std::min(ans, map["A"] + map["B"] + map["C"]);
	ans = std::min(ans, map["AB"] + map["AC"]);
	ans = std::min(ans, map["AB"] + map["BC"]);
	ans = std::min(ans, map["AC"] + map["BC"]);
	ans = std::min(ans, map["A"] + map["BC"]);
	ans = std::min(ans, map["AB"] + map["C"]);
	ans = std::min(ans, map["B"] + map["AC"]);
	if (ans > 1000000) { printf("-1\n"); }
	else { printf("%d\n", ans); }
	return 0;
}