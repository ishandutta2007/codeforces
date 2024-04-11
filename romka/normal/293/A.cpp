#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

char s[2000010], t[2000010];

int solve(int i, int j, int k, int l) {
	l &= 1;
	int kj = min(j, k);
	j -= kj;
	k -= kj;
	if (l) {
		if (j > 0) l -= (j+1)/2;
		else l += k/2;
	} else {
		if (j > 0) l -= j/2;
		else l += (k+1)/2;
	}
	return l;
}

int main() {
	int n;
	scanf("%d", &n);
	n <<= 1;
	scanf("%s", s);
	scanf("%s", t);

	int a = 0, b = 0, c = 0, d = 0;
	forn(i, n) {
		a += s[i] == '0' && t[i] == '0';
		b += s[i] == '0' && t[i] == '1';
		c += s[i] == '1' && t[i] == '0';
		d += s[i] == '1' && t[i] == '1'; 
	}

	int z = solve(a, b, c, d);
	if (z > 0) printf("First\n");
	if (z == 0) printf("Draw\n");
	if (z < 0) printf("Second\n");
	
	return 0;
}