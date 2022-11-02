#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2111;

int a[N];
int b[N];

int p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < n; i ++)
		cin >> b[i];
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(a[j] == b[i])
				p[j] = i;

	long long ans = 0;
	vector <pair <int, int> > vec;
	for(int i = 0; i < n; i ++)
	{
		int pos = 0;
		for(int j = i; j < n; j ++)
			if(p[j] == i)
				pos = j;
		while(pos != i)
		{
			for(int j = pos - 1; j >= i; j --)
				if(p[j] >= pos)
				{
					vec.push_back(make_pair(j, pos));
					ans += pos - j;
					swap(p[j], p[pos]);
					pos = j;
					break;
				}
		}
	}

	cout << ans << '\n';
	cout << vec.size() << '\n';
	for(int i = 0; i < vec.size(); i ++)
		cout << vec[i].first + 1 << ' ' << vec[i].second + 1 << '\n';
	
	return 0;
}