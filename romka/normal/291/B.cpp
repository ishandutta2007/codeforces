#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

char s[100010], t[100010];

int main() {
	gets(s);
	int n = strlen(s);
	bool inside = false;
	const char Q = 1;
	forn(i, n) {
		if (s[i] == '"') inside ^= 1;
		if (s[i] == ' ' && inside)
			s[i] = Q;
	}

	int k = 0;
	forn(i, n)
		if (s[i] != ' ' || (i > 0 && s[i-1] != ' '))
			t[k++] = s[i];

	if (t[k-1] != ' ')
		t[k++] = ' ';
	
	string cur = "";
	forn(i, k)
		if (t[i] == ' ') {
			printf("<%s>\n", cur.c_str());
			cur = "";
		} else if (t[i] != '"') cur += t[i] == Q ? ' ' : t[i];

	return 0;
}