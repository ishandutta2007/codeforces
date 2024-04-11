#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int N;
int as, at;
int bs, bt;

int main()
{
	cin >> N;
	as = at = bs = bt = 0;
	int a, b, c;
	
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			as += b;
			at += 10;
		}
		else
		{
			bs += b;
			bt += 10;
		}
	}
	if (as * 2 >= at)
		cout << "LIVE\n";
	else
		cout << "DEAD\n";
	if (bs * 2 >= bt)
		cout << "LIVE\n";
	else
		cout << "DEAD\n";
	return 0;
}