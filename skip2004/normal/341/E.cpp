#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 1010;
int n;
int a[N];

std::vector<std::pair<int, int>> res;
inline void push_op(int x, int y)
{
	if(a[x] <= a[y])
	{
		res.emplace_back(x, y);
		a[y] -= a[x];
		a[x] <<= 1;
	}
	else
		exit(1);
}
inline void relax(int x, int y, int z)
{
	do {
		std::array<int, 3> arr = {x, y, z};
		std::sort(arr.begin(), arr.end(), [](int x, int y) { return a[x] < a[y]; });
		x = arr[0], y = arr[1], z = arr[2];
		int div = a[y] / a[x];
		for(;div;) {
			if(div & 1) push_op(x, y), div >>= 1;
			else if(div >>= 1) push_op(x, z);
		}
		std::swap(x, y);
	} while(a[x] && a[y] && a[z]);
}
int main()
{
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	std::for_each(a + 1, a + n + 1, [](int & x) { cin >> x; });
	if(std::count(a + 1, a + n + 1, 0) > n - 2)
	{
		cout << -1 << '\n';
		return 0;
	}
	while(std::count(a + 1, a + n + 1, 0) < n - 2) {
		std::vector<int> bak;
		for(int i = 1;i <= n;++i) if(a[i] != 0) {
			bak.push_back(i);
		}
		for(int i = 0;i + 2 < bak.size();i += 3)
			relax(bak[i], bak[i + 1], bak[i + 2]);
	}
	cout << res.size() << '\n';
	for(auto i : res) {
		cout << i.first << ' ' << i.second << '\n';
	}
	for(int i = 1;i <= n;++i) {
//		cout << a[i] << ' ' ;
	}
}