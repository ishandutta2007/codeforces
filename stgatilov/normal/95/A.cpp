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
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int n, l;
string str, arr[128];
bool ch[128];
char letter;

char tl(char c) {
	return (c>='a' && c<='z' ? c : char(c + 'a'-'A'));
}

string tl(const string &s) {
	string res;
	for (int i = 0; i<s.size(); i++)
		res += tl(s[i]);
	return res;
}

char buff[65536];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%s", buff);
		arr[i] = buff;
	}
	scanf("%s", buff);
	str = buff;
	l = str.size();
	scanf("%s", buff);
	letter = buff[0];

	for (int i = 0; i<l; i++) {
		for (int j = 0; j<n; j++)
			if (i + arr[j].size() <= l && tl(str.substr(i, arr[j].size())) == tl(arr[j])) {
				for (int u = i; u<i + arr[j].size(); u++)
					ch[u] = true;
			}
	}

	for (int u = 0; u<l; u++) if (ch[u]) {
		if (tl(str[u]) == letter) {
			char nc = (letter == 'a' ? 'b' : 'a');
			str[u] += nc - tl(str[u]);
		}
		else str[u] += letter - tl(str[u]);
	}

	printf("%s\n", str.c_str());

	return 0;
}