#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 100100;

int N, M;
string str;
int xcount[MAXN];
int ycount[MAXN];
int zcount[MAXN];

int arr[3];

int main()
{
	cin >> str;
	N = str.length();
	
	xcount[0] = ycount[0] = zcount[0] = 0;
	for (int i = 0; i < N; i++)
	{
		xcount[i+1] = xcount[i];
		ycount[i+1] = ycount[i];
		zcount[i+1] = zcount[i];
		
		if (str[i] == 'x')
			xcount[i+1]++;
		else if (str[i] == 'y')
			ycount[i+1]++;
		else
			zcount[i+1]++;
	}
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int t, t2;
		cin >> t >> t2;
		
		arr[0] = xcount[t2] - xcount[t-1];
		arr[1] = ycount[t2] - ycount[t-1];
		arr[2] = zcount[t2] - zcount[t-1];
		
		sort (arr, arr + 3);
		
		if ((arr[0] == 0 && arr[1] == 0 && arr[2] == 2) || (arr[2] - arr[0] <= 1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}