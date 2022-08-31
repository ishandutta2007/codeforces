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
	int ans[110];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		ans[x-1] = i + 1;
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	cout << "\n";
}