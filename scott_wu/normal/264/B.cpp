#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int arr[MAXN];
int bp[MAXN];
vector <int> p;

int main()
{
	for (int i = 0; i < MAXN; i++)
		bp[i] = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 1)
			ans = max (ans, 1);
		
		p.clear();
		
		int temp = arr[i];
		int bval = 0;
		for (int j = 2; j * j <= temp; j++)
			if (temp % j == 0)
			{
				p.push_back (j);
				bval = max (bval, bp[j] + 1);
				
				while (temp % j == 0)
					temp /= j;
			}
		if (temp > 1)
		{
			p.push_back (temp);
			bval = max (bval, bp[temp] + 1);
		}
		
		ans = max (ans, bval);
		for (int j = 0; j < p.size(); j++)
		{
			//cout << p[j] << "\n";
			bp[p[j]] = max (bp[p[j]], bval);
		}
		//cout << "\n";
	}
	
	cout << ans << "\n";
	return 0;
}