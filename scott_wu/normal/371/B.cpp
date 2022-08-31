#include <iostream>

using namespace std;

int gcf (int a, int b)
{
	return ((b == 0) ? a : gcf (b, a % b));
}

int main()
{
	int x, y;
	cin >> x >> y;
	
	int g = gcf (x, y);
	x /= g; y /= g;
	
	long long t = x * (long long) y;
	int cnt = 0;
	while (t % 2 == 0)
	{
		t /= 2;
		cnt++;
	}
	while (t % 3 == 0)
	{
		t /= 3;
		cnt++;
	}
	while (t % 5 == 0)
	{
		t /= 5;
		cnt++;
	}
	
	if (t == 1)
		cout << cnt << "\n";
	else
		cout << "-1\n";
	return 0;
}