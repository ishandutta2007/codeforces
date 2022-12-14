#include<iostream>
using namespace std;
int main()
{
	bool y = false;
	int num;
	cin >> num;
	for (int i = 1; i < num; i++)
	{
		int j;
		j = num - i;
		if (i % 2 == 0 && j % 2 == 0)
			y = true;
	}
	if (y == true)
		cout << "yes";
	else
		cout << "no";

}