#include <iostream>
using namespace std;

string str[3] = {"IMPOSSIBLE", "SEGMENT", "TRIANGLE"};

int check(int a, int b, int c)
{
	if(a + b < c || abs(a - b) > c)
		return 0;
	if(a + b > c && abs(a - b) < c)
		return 2;
	return 1;
}

int main()
{
	ios :: sync_with_stdio(false);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0;
	ans = max(ans, check(a, b, c));
	ans = max(ans, check(a, b, d));
	ans = max(ans, check(a, c, d));
	ans = max(ans, check(b, c, d));
	cout << str[ans] << '\n';
	return 0;
}