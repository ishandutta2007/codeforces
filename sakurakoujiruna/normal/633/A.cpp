#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	bool flag = false;
	for(int i = 0; a * i <= c; i ++)
		if((c - a * i) % b == 0)
			flag = true;
	if(flag)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}