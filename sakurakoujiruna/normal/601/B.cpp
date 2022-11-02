#include <iostream>
using namespace std;

const int N = 101111;
int a[N];
pair <int, int> sta[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	while(q --)
	{
		int top = 0;
		long long ans = 0;
		long long sum = 0;
		int l, r;
		cin >> l >> r;
		for(int i = l; i < r; i ++)
		{
			int tmp = abs(a[i] - a[i + 1]);
			int acc = 0;
			while(top > 0 && sta[top - 1].first < tmp)
			{
				sum -= (long long)sta[top - 1].first * sta[top - 1].second;
				acc += sta[top - 1].second;
				top --;
			}
			sum += (long long)(acc + 1) * tmp;
			sta[top ++] = make_pair(tmp, acc + 1);
			ans += sum;
		}
		cout << ans << '\n';
	}
	return 0;
}