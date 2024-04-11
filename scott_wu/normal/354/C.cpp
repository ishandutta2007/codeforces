#include <iostream>

using namespace std;
const int MAXK = 1000100;

int N, K;
int nocc[MAXK];
int ps[2*MAXK];

bool works (int x)
{
	int tot = 0;
	for (int i = x; i < MAXK; i += x)
		tot += ps[min (i + x, i + K + 1)] - ps[i];
	return tot >= N;
}

int main()
{
	for (int i = 0; i < MAXK; i++)
		nocc[i] = 0;
	
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		nocc[x]++;
	}
	
	ps[0] = 0;
	for (int i = 0; i < MAXK; i++)
		ps[i+1] = ps[i] + nocc[i];
	for (int i = MAXK; i < 2 * MAXK - 1; i++)
		ps[i+1] = ps[i];
	
	for (int i = 1000000; i >= 1; i--)
		if (works (i))
		{
			cout << i << "\n";
			break;
		}
	return 0;
}