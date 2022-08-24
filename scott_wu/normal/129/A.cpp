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
	int N;
	int a[110];
	int sum = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++)
		if (sum % 2 == a[i] % 2)
			ans++;
	cout << ans << "\n";
	return 0;
}