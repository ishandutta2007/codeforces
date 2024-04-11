#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int M, N;
int mq;
int arr[MAXN];
int sum;

int main()
{
	cin >> M;
	mq = MAXN;
	for (int i = 0; i < M; i++)
	{
		int x; cin >> x;
		mq = min (mq, x);
	}
	
	cin >> N; sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	
	sort (arr, arr + N);
	
	for (int i = N - 1; i >= 0; i--)
	{
		int cval = N - i - 1;
		if (cval % (mq + 2) >= mq)
			sum -= arr[i];
	}
	cout << sum << "\n";
	return 0;
}