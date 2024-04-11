#include <iostream>
#include <algorithm>
using namespace std;

const int N = 53;
int b[N];
int a[N];

int main()
{
	ios :: sync_with_stdio(false);

	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> b[i];
	sort(b, b + n);

	int cnt = 1;
	a[0] = b[0];
	for(int i = 1; i < n; i ++)
		if(b[i] != b[i - 1])
		{
			a[cnt ++] = b[i];
		}
	n = cnt;
	for(int i = 0; i < n; i ++)
		for(int j = i + 2; j < n; j ++)
			if(a[j] - a[i] <= 2)
			{
				cout << "YES\n";
				return 0;
			}
	cout << "NO\n";

	return 0;
}