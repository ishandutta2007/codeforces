#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

int n, m, s;
const int MAXN = 100000;
struct stud
{
	int skill;
	int cost;
	int id;
};
struct bug
{
	int diff;
	int id;
};

bug a[MAXN];
stud b[MAXN];

bool read()
{
	if (!(cin >> m >> n >> s))
		return false;
	forn (i, n)
	{
		cin >> a[i].diff;
		a[i].id = i;
	}
	forn (i, m)
		cin >> b[i].skill;
	forn (i, m)
		cin >> b[i].cost;
	forn (i, m)
		b[i].id = i;
	return true;
}

bool ok (int maxLen)
{
	li sum = 0;
	set<pair<int, int> > cur;
	int l = m - 1;
	vector<int> cnt(m, 0);
	for (int i = n - 1; i >= 0; --i)
	{
		while (l >= 0 && b[l].skill >= a[i].diff)
		{
			cur.insert(mp(b[l].cost, l));
			l--;
		}
		if (cur.empty())
			return false;
		int id = cur.begin()->second;
		cnt[id]++;
		sum += b[id].cost;
		b[id].cost = 0;
		cur.erase(cur.begin());
		if (cnt[id] != maxLen)
			cur.insert(mp(b[id].cost, id));
	}
	return sum <= s;
}
vector<int> ans;
void restore (int maxLen)
{
	li sum = 0;
	set<pair<int, int> > cur;
	int l = m - 1;
	vector<int> cnt(m, 0);
	for (int i = n - 1; i >= 0; --i)
	{
		while (l >= 0 && b[l].skill >= a[i].diff)
		{
			cur.insert(mp(b[l].cost, l));
			l--;
		}
		int id = cur.begin()->second;
		cnt[id]++;
		ans[a[i].id] = b[id].id + 1;
		sum += b[id].cost;
		b[id].cost = 0;
		cur.erase(cur.begin());
		if (cnt[id] != maxLen)
			cur.insert(mp(b[id].cost, id));
	}
}
bool cmp1(bug &A, bug &B)
{
	if (A.diff != B.diff)
		return A.diff < B.diff;
	return A.id < B.id;
}
bool cmp2(stud &A, stud &B)
{
	if (A.skill != B.skill)
		return A.skill < B.skill;
	return A.id < B.id;
}

void solve()    
{
	ans.resize(n);
	sort(a, a + n, cmp1);
	sort(b, b + m, cmp2);
	vector<int> otcost(m);
	forn (i, m)
		otcost[i] = b[i].cost;
	int l = 1, r = n;
	while (r - l > 1)
	{
		forn (i, m)
			b[i].cost = otcost[i];
		int mid = (r + l) / 2;
		if (ok(mid))
			r = mid;
		else
			l = mid;
	}
	forn (i, m)
		b[i].cost = otcost[i];

	while (r > 1 && ok(r - 1))
	{
		r--;
		forn (i, m)
			b[i].cost = otcost[i];
	}

	forn (i, m)
		b[i].cost = otcost[i];

	if (ok(r))
	{
		cout << "YES" << endl;
		forn (i, m)
			b[i].cost = otcost[i];
		restore(r);
		forn (i, n)
			cout << ans[i] << ' ';
		cout << endl;
	}
	else
		cout << "NO" << endl;
}

int main()
{
#ifdef Baster
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	read();
	solve();
	return 0;
}