#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100100;

int N, P, K;
pair <pair <int, int>, int> ord[MAXN];
bool use[MAXN];

inline bool cmp (pair <pair <int, int>, int> left, pair <pair <int, int>, int> right)
{
	if (left.first.second != right.first.second)
		return left.first.second < right.first.second;
	if (left.first.first != right.first.first)
		return left.first.first > right.first.first;
	return left.second < right.second;
}

inline bool cmp2 (pair <pair <int, int>, int> left, pair <pair <int, int>, int> right)
{
	if (left.first.first != right.first.first)
		return left.first.first > right.first.first;
	if (left.first.second != right.first.second)
		return left.first.second > right.first.second;
	return left.second < right.second;
}

int main()
{
	for (int i = 0; i < MAXN; i++)
		use[i] = false;
	
	cin >> N >> P >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> ord[i].first.first >> ord[i].first.second;
		ord[i].second = i + 1;
	}
	
	sort (ord, ord + N, cmp);
	sort (ord + P - K, ord + N, cmp2);
	
	for (int i = P - K; i < P; i++)
	{
		use[ord[i].second] = true;
		cout << ord[i].second << " ";
	}
	
	sort (ord, ord + N, cmp);
	for (int i = 0; i < N; i++)
		if (use[ord[i].second])
		{
			for (int j = i - 1; j >= i - P + K; j--)
				cout << ord[j].second << " ";
			cout << "\n";
			return 0;
		}
}