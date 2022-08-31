#include <iostream>

using namespace std;

int main()
{
	int N; cin >> N;
	cout << (N * N + 1) / 2 << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if ((i + j) % 2 == 0)
				cout << 'C';
			else
				cout << '.';
		cout << "\n";
	}
	return 0;
}