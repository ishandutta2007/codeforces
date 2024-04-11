#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
int a[110000];

multiset < int > S;

bool check(int t)
{
	S.clear();
	for (int i = 1; i <= t; i ++)
		S.insert(a[i]);
	for (int i = t; i <= n; i ++)
	{
		int x = * S.begin();
		int y = * S.rbegin();
		if (y - x <= k) return true;
		S.erase(S.find(a[i + 1 - t]));
		S.insert(a[i + 1]);
	}
	return false;
}

vector < int > ans;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	int l = 1, r = n;
	while (r - l > 1)
	{
		int key = (l + r) / 2;
		if (check(key))
			l = key; else
			r = key;
	}
	int res = l;
	if (check(r)) res = r;
	S.clear();
	for (int i = 1; i <= res; i ++)
		S.insert(a[i]);
	for (int i = res; i <= n; i ++)
	{
		int x = * S.begin();
		int y = * S.rbegin();
		if (y - x <= k) ans.push_back(i - res + 1);
		S.erase(S.find(a[i + 1 - res]));
		S.insert(a[i + 1]);
	}

	printf("%d %d\n", res, ans.size());
	for (int i = 0; i < ans.size(); i ++)
		printf("%d %d\n", ans[i], ans[i] + res - 1);
	return 0;
}