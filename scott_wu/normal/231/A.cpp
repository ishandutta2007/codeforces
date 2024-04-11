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
	int N; cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 3; j++)
		{
			int x; cin >> x; cnt += x;
		}
			if (cnt >= 2)
				ans++;
			}
			cout << ans << "\n";
		}