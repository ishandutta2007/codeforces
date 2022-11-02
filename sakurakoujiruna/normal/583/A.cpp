#include <iostream>
using namespace std;

const int N = 53;
bool vis1[N];
bool vis2[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n * n; i ++)
	{
		int x, y;
		cin >> x >> y;
		if((!vis1[x]) && (!vis2[y]))
		{
			cout << i << ' ';
			vis1[x] = true;
			vis2[y] = true;
		}
	}
	cout << '\n';
	return 0;
}