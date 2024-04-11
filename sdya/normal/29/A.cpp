#include <iostream>

using namespace std;

int x[200], d[200];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> x[i] >> d[i];

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (x[i] + d[i] == x[j] && x[i] == x[j] + d[j] && i != j)
			{
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}