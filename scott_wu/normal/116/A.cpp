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
	int ans = 0, val = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		val += b - a;
		ans = max (ans, val);
	}
	cout << ans << "\n";
}