#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	int best = 0, nb = 0;
	
	int N, M;
	int a[55], b[55];
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> b[i];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if ((b[j] / a[i]) * a[i] == b[j])
			{
				if (b[j] / a[i] > best)
				{
					best = b[j] / a[i];
					nb = 1;
				}
				else if (b[j] / a[i] == best)
				{
					nb++;
				}
			}
		}
	cout << nb << "\n";
	return 0;
}