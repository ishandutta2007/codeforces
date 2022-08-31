#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 2000001;
const int LG = 21;

char s[MAXN];

int n;
int a[MAXN];
int pref[MAXN];
int suf[MAXN];
pair <int, int> pp[MAXN];
int p[MAXN];
int c[MAXN];
int as1[MAXN];
int as2[MAXN];

inline int get_bal(int x)
{
	return min(suf[x] - a[x], a[n] - a[x] + pref[x]);
}

int main()
{
	scanf("%s",s);
	n = strlen(s);
	if (n == 1)
	{
		cout << "()" << endl;
		return 0;
	}
	a[0] = 0;
	int adb = 0;
	pref[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(') a[i + 1] = a[i] + 1, adb++;
		else a[i + 1] = a[i] - 1, adb--;
		pref[i + 1] = min(pref[i], a[i + 1]);
	}
	suf[n] = a[n];
	for (int i = n - 1; i >= 0; i--) suf[i] = min(suf[i + 1], a[i]);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(') c[i] = 0;
		else c[i] = 1;
	}
	for (int j = 1; j < LG; j++)
	{
		int pi = (1 << (j - 1));
		for (int i = 0; i < n; i++)
		{
			pp[i] = make_pair(c[i], c[pi]);
			as1[i] = i;
			pi++;
			if (pi == n) pi = 0;
		}
        memset(p, 0, n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			p[pp[as1[i]].second]++;
		}
		for (int i = 1; i < n; i++) p[i] += p[i - 1];
		for (int i = n - 1; i >= 0; i--)
		{
			as2[--p[pp[as1[i]].second]] = as1[i];
		}
        memcpy(as1, as2, n * sizeof(int));

        memset(p, 0, n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			p[pp[as1[i]].first]++;
		}
		for (int i = 1; i < n; i++) p[i] += p[i - 1];
		for (int i = n - 1; i >= 0; i--)
		{
			as2[--p[pp[as1[i]].first]] = as1[i];
		}
        memcpy(as1, as2, n * sizeof(int));

		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			if ((i != 0) && (pp[as1[i]] != pp[as1[i - 1]])) cur++;
			c[as1[i]] = cur;
		}
	}
	int bb = -n - 1, bc = n * 2, bid = -1;
	for (int i = 0; i < n; i++)
	{
		int nb = get_bal(i);
		if (make_pair(nb, -c[i]) > make_pair(bb, -bc)) bb = nb, bc = c[i], bid = i;
	}
	int ad = -get_bal(bid);
	for (int i = 0; i < ad; i++) printf("(");
	adb += ad;
	for (int i = 0; i < n; i++) printf("%c", s[(i + bid) % n]);
	for (int i = 0; i < adb; i++) printf(")");
	printf("\n");
	return 0;
}