#include <iostream>
#include <set>
using namespace std;

const int N = 200011;

multiset <int> ms;

pair <int, int> sta[N];
int a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		a[i] = x;
	}
	int top = 0;
	for(int i = 0; i < m; i ++)
	{
		int t, r;
		cin >> t >> r;
		while(top > 0 && r >= sta[top - 1].first)
			top --;
		sta[top ++] = {r, t};
	}
	sta[top ++] = {0, 0};
	for(int i = 1; i <= sta[0].first; i ++)
		ms.insert(a[i]);
	for(int i = 0; i < top - 1; i ++)
		if(sta[i].second == 1)
			for(int j = sta[i].first; j > sta[i + 1].first; j --)
			{
				auto it = ms.rbegin();
				a[j] = *it;
				ms.erase(ms.find(*it));
			}
		else
			for(int j = sta[i].first; j > sta[i + 1].first; j --)
			{
				auto it = ms.begin();
				a[j] = *it;
				ms.erase(it);
			}
	for(int i = 1; i <= n; i ++)
		cout << a[i] << ' ';
	cout << '\n';
	return 0;
}