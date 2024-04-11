#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;

#define ll long long
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); ++a)
#define iter(a) typeof(a.begin())
#define foreach(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define sqr(a) (a)*(a)
#define PI 2.0*acos(0.0)

const int INF = 1000000001;
const double EPS = 1e-8;
const int MAXN = 100002;
const int MAXC = 102;
int c[MAXN];
int last[MAXN];
int a[MAXN];
int b[MAXN];
int col[MAXN];
int newA[MAXN];
int newCol[MAXN];

int toc[MAXC];
int lcp[MAXN];

char s[MAXN + 1];

int al[MAXN];
int p[MAXN];
int n;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("towers.out", "w", stdout);
	clr(s);
	scanf("%s", &s);
	int K;
	scanf("%d", &K);
	n = strlen(s);
	FOR(i, n)
	{
		s[i] -= 'a';
		s[i]++;
	}

	s[n++] = 0;
	clr(c);
	FOR(i, n)
		c[s[i]]++;
	int cnt = 0;
	FOR(i, MAXC)
		if (c[i] != 0)
		{
			toc[i] = cnt++;
			c[toc[i]] = c[i];
		}
	int w = 0;
	FOR(i, cnt)
	{
		last[i] = w;
		w += c[i];
	}
	FOR(i, n)
	{
		a[last[toc[s[i]]]] = i;
		col[i] = toc[s[i]];
		last[toc[s[i]]]++;
	}
	w = 0;
	FOR(i, cnt)
	{
		last[i] = w;
		w += c[i];
	}
	int k = 1;
	while (k < n)
	{
		FOR(i, n)
		{
			int prev = (a[i] - k + n) % n;
			newA[last[col[prev]]] = prev;
			last[col[prev]]++;
		}
		FOR(i, n)
			a[i] = newA[i];
		int cnt = 0;
		last[0] = 0;
		newCol[a[0]] = cnt;
		for (int i = 1; i < n; ++i)
		{
			if (col[a[i]] != col[a[i - 1]] || col[(a[i] + k) % n] != col[(a[i - 1] + k) % n])
			{
				cnt++;
				last[cnt] = i;
			}

			newCol[a[i]] = cnt;
		}
		FOR(i, n)
			col[i] = newCol[i];

		k *= 2;
	}
	n--;
	FOR(i, n)
		a[i] = a[i + 1];
	FOR(i, n)
		b[a[i]] = i;
	clr(lcp);

	for (int i = 0; i < n; ++i)
	{
		if (i != 0 && lcp[b[i - 1]] != 0)
			lcp[b[i]] = lcp[b[i - 1]] - 1;
		if (b[i] == 0)
		{
			lcp[b[i]] = 0;
			continue;
		}
		int w1 = (i + lcp[b[i]]);
		int w2 = (a[b[i] - 1] + lcp[b[i]]);
		while (w1 < n && w2 < n && s[w1] == s[w2])
		{
			lcp[b[i]]++;
			w1++;
			w2++;
		}
	}	
	/*
	FOR(i, n)
	{
		for (int j = a[i]; j < n; ++j)
			printf("%c", s[j] + 'a' - 1);
		printf("\n");
	}
return 0;	

	FOR(i, n)
		cerr << lcp[i] << ' ';
	cerr << endl;
	
*/
	FOR(i, n)
		al[i] = n - a[i];
	clr(p);
	int p1 = 0;
	int i = 0;
	set <int> use;
	FOR(i, n)
		use.insert(i);
	while (true)
	{
		p[p1]++;
		if (p[p1] >= al[p1])
			use.erase(p1);
		i++;
		if (i == K)
		{
			for (int j = a[p1]; j < a[p1] + p[p1]; ++j)
				printf("%c", s[j] + 'a' - 1);
			return 0;
		}
		if (p1 < n && lcp[p1 + 1] >= p[p1])
			p1++;
		else
		{
			if (use.begin() == use.end())
				break;
			p1 = (*use.begin());
		}
	}
	printf("No such line.");





	return 0;
}