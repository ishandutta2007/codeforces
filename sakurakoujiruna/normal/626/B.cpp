#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	string str;
	cin >> str;
	int r = 0, g = 0, b = 0;
	for(auto &c : str)
	{
		if(c == 'R')
			r ++;
		else if(c == 'G')
			g ++;
		else
			b ++;
	}
	if(r > 0 && g > 0 && b > 0)
		cout << "BGR\n";
	else if(r > 0 && g > 0)
	{
		if(r == 1 && g == 1)
			cout << "B\n";
		else if(r >= 2 && g == 1)
			cout << "BG\n";
		else if(r == 1 && g >= 2)
			cout << "BR\n";
		else
			cout << "BGR\n";
	}
	else if(r > 0 && b > 0)
	{
		if(r == 1 && b == 1)
			cout << "G\n";
		else if(r >= 2 && b == 1)
			cout << "BG\n";
		else if(r == 1 && b >= 2)
			cout << "GR\n";
		else
			cout << "BGR\n";
	}
	else if(b > 0 && g > 0)
	{
		if(b == 1 && g == 1)
			cout << "R\n";
		else if(b >= 2 && g == 1)
			cout << "GR\n";
		else if(b == 1 && g >= 2)
			cout << "BR\n";
		else
			cout << "BGR\n";
	}
	else if(r > 0)
		cout << "R\n";
	else if(g > 0)
		cout << "G\n";
	else
		cout << "B\n";
	return 0;
}