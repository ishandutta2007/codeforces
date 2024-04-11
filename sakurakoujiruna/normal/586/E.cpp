#include <iostream>
using namespace std;

long long gcd(long long x, long long y)
{
	if(y == 0)
		return x;
	return gcd(y, x % y);
}

string num2string(long long x)
{
	string ret = "";
	while(x != 0)
	{
		ret = (char)('0' + x % 10) + ret;
		x /= 10;
	}
	return ret;
}

void gcd(long long x, long long y, bool b, string &str)
{
	if(x < y)
		gcd(y, x, !b, str);
	else if(y == 1)
		if(x > 1)
		{
			str += num2string(x - 1);
			str += (char)('A' + b);
		}
		else { }
	else
	{
		str += num2string(x / y);
		str += (char)('A' + b);
		gcd(x % y, y, b, str);
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	long long x, y;
	cin >> x >> y;

	if(gcd(x, y) != 1)
		cout << "Impossible" << '\n';
	else
	{
		string str;
		gcd(x, y, 0, str);

		cout << str << '\n';
	}
	return 0;
}