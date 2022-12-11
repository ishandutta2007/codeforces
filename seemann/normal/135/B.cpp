#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;

struct point{
	int x, y;
	int n;
};

point operator - (point a, point b)
{
	point w;
	w.x = a.x - b.x;
	w.y = a.y - b.y;
	return w;
}

point a[10];
int n;
point b[6];
point c[6];
bool use[10];

int m;
void rek(int step)
{
	if (step == n)
	{
		b[m] = b[0];
		c[m] = c[0];
		point w[6];
		FOR(i, m)
			w[i] = b[i + 1] - b[i];
		w[m] = w[0];
		FOR(i, m)
			if (w[i].x * w[i + 1].x != - w[i].y * w[i + 1].y)
				return;
		FOR(i, m)
			if(abs(w[i].x) != abs(w[i + 1].y) || abs(w[i].y) != abs(w[i + 1].x))
				return;
		FOR(i, m)
			w[i] = c[i + 1] - c[i];
		w[m] = w[0];
		FOR(i, m)
			if (w[i].x * w[i + 1].x != - w[i].y * w[i + 1].y)
				return;
		printf("YES\n");
		FOR(i, m)
			printf("%d ", b[i].n);
		printf("\n");
		FOR(i, m)
			printf("%d ", c[i].n);
		exit(0);
	}
	FOR(i, n)
	{
		if (use[i])
			continue;
		if (step < m)
			b[step] = a[i];
		else
			c[step - m] = a[i];
		use[i] = true;
		rek(step + 1);
		use[i] = false;
	}
	return;
}



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	n = 8;
	m = 4;
	FOR(i, n)
		cin >> a[i].x >> a[i].y;
	FOR(i, n)
		a[i].n = i + 1;
	clr(use);
	rek(0);
	printf("NO");
	return 0;
}