#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 5100;
const int MAXM = 1000100;

int N, K;
int arr[MAXN];

int bad[MAXM];
int seen[MAXM];

bool works (int val)
{
	int nbad = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (nbad > K) return false;
		
		int v = arr[i] % val;
		if (seen[v] == val)
			nbad++;
		else
			seen[v] = val;
	}
	
	return nbad <= K;
}

int main()
{
	for (int i = 0; i < MAXM; i++)
	{
		seen[i] = -1;
		bad[i] = 0;
	}
	
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int i = 1; i < N; i++)
	{
		int nplace = rand() % (i + 1);
		swap (arr[i], arr[nplace]);
	}
	
	if (N <= K)
	{
		cout << "1\n";
		return 0;
	}
	
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			int diff = abs (arr[i] - arr[j]);
			for (int k = 1; k <= 5; k++)
				if (diff % k == 0)
					bad[diff / k]++;
		}
	
	for (int i = N - K; i < MAXM; i++)
	{
		if (bad[i] > (K * (K + 1)) / 2)
			continue;
		if (works (i))
		{
			cout << i << "\n";
			return 0;
		}
	}
	
	return 0;
}