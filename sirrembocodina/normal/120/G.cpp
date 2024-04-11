#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


struct team
{
	pair<int, int> p[2];
};

int n, t, m, cnt, tm, pl;
team A[200];
string w[200];
int c[200], pt[200];
int ans[200][200];
int d[200][200];
int B[200];

void shift()
{
	for (int i = 0; i < cnt - 1; i++)
		B[i] = B[i + 1];
}

void del(int tm, int k)
{
	ans[tm][pt[tm]] = k;
	pt[tm]++;
	shift();
	cnt--;
}

void step(int tm, int pl)
{
	int s = t;
	while ((s > 0) && (cnt > 0))
	{
		int k = B[0];
		int i = tm; int j = pl;
		int q = 1 - pl;
		int tt = max(1, c[k] - (A[i].p[j].fs + A[i].p[q].sc) - d[i][k]);
		if (s >= tt)
		{
			s -= tt;
			del(i, k);
		}
		else
		{
			d[i][k] += s;
			shift();
			B[cnt - 1] = k;
			return;
		}

	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d\n", &n, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d \n", &A[i].p[0].fs, &A[i].p[0].sc, &A[i].p[1].fs, &A[i].p[1].sc);
		pt[i] = 0;
	}
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++)
	{
		B[i] = i;
		w[i] = "";
		while (w[i] == "")
			getline(cin, w[i]);
		//cin >> w[i];
		cin >> c[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = 0;
	cnt = m;
	tm = 0;
	pl = 0;
	while (cnt > 0)
	{
		step(tm, pl);
		tm++;
		if (tm == n)
		{
			tm = 0;
			pl = 1 - pl;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << pt[i];
		for (int j = 0; j < pt[i]; j++)
			cout << " " << w[ans[i][j]];
		cout << endl;

	}

	fclose(stdin);
	fclose(stdout);

    return 0;
}