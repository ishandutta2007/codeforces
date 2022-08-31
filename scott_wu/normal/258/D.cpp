#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M;
int arr[MAXN];
double prob[MAXN][MAXN];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (arr[i] < arr[j])
				prob[i][j] = 1.0;
			else
				prob[i][j] = 0.0;
		}
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		
		prob[a][b] = prob[b][a] = 0.5;
		
		for (int j = 0; j < N; j++)
		{
			if (j != a && j != b)
			{
				double nprob = (prob[j][a] + prob[j][b]) / 2.0;
				prob[j][a] = prob[j][b] = nprob;
				prob[a][j] = prob[b][j] = 1.0 - nprob;
			}
		}
	}
	
	double ans = 0.0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
		{
			ans += prob[i][j];
			//cout << prob[i][j] << "\n";
		}
	
	cout << fixed << setprecision (7);
	cout << ans << "\n";
	return 0;
}