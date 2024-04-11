#include <iostream>

using namespace std;

int N, K;
int arr[110];
int cnt[110];

int main()
{
	for (int i = 0; i < 110; i++)
		cnt[i] = 0;
	
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		
		if (x == 1)
			cnt[i%K]++;
	}
	
	int ans = 0;
	for (int i = 0; i < K; i++)
		ans += min (cnt[i], N / K - cnt[i]);
	cout << ans << "\n";
	return 0;
}