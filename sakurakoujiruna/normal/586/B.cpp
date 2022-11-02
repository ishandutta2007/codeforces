#include <iostream>
using namespace std;

const int N = 53;
int a[N];
int b[N];
int c[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++)
		cin >> a[i];
	for(int i = 1; i < n; i ++)
		cin >> b[i];
	for(int i = 1; i <= n; i ++)
		cin >> c[i];

	int ans = 0x3f3f3f3f;

	for(int i = 1; i < n; i ++)
		for(int j = i + 1; j <= n; j ++)
		{
			int tmp = 0;
			tmp += c[i];
			for(int k = 1; k < n; k ++)
				if(k < i)
					tmp += a[k];
				else
					tmp += b[k];

			tmp += c[j];
			for(int k = 1; k < n; k ++)
				if(k < j)
					tmp += a[k];
				else
					tmp += b[k];

			ans = min(ans, tmp);
		}

	cout << ans << '\n';
	return 0;
}