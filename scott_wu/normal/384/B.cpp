#include <iostream>

using namespace std;

int main()
{
	int M, K;
	cin >> M >> M >> K;
	
	cout << (M * (M - 1)) / 2 << "\n";
	for (int i = 1; i < M; i++)
		for (int j = i + 1; j <= M; j++)
			cout << ((K) ? j : i) << " " << ((K) ? i : j) << "\n";
	return 0;
}