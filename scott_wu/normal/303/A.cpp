#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
	int N; cin >> N;
	
	if (N % 2 == 0)
	{
		cout << "-1\n";
		return 0;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (i > 0) cout << " ";
		cout << i;
	}
	cout << "\n";
	
	for (int i = 0; i < N; i++)
	{
		if (i > 0) cout << " ";
		cout << (2 * N - 2 * i) % N;
	}
	cout << "\n";
	
	for (int i = 0; i < N; i++)
	{
		if (i > 0) cout << " ";
		cout << (N - i) % N;
	}
	cout << "\n";
	return 0;
}