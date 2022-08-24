#include <iostream>

using namespace std;

int main()
{
	int N;
	int num[110];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	int count = 0, loc = -1;
	for (int i = 0; i < N; i++)
		if (num[i] % 2)
		{
			count++;
			loc = i;
		}
	
	if (count == 1)
	{
		cout << loc + 1 << "\n";
		return 0;
	}
	
	count = 0, loc = -1;
	for (int i = 0; i < N; i++)
		if (num[i] % 2 == 0)
		{
			count++;
			loc = i;
		}
	cout << loc + 1 << "\n";
	return 0;
}