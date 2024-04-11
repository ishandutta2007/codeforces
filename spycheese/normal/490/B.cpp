#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;

const int N = 200500;
const int K = 1005005;
const int INF = 0x3f3f3f3f;

int n, a[N], b[N];
int a2i[K], b2i[K];
int answer[N];
int fir;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w", stdout);

	memset(a2i, -1, sizeof(a2i));
	memset(b2i, -1, sizeof(b2i));
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i] >> b[i];
		a2i[a[i]] = i;
		b2i[b[i]] = i;
		if (a[i] == 0)
			fir = i;
	}

	int curr = fir;
	for (int i = 0; i + 1 < n; i += 2)
	{
		answer[i + 1] = b[curr];
		curr = a2i[b[curr]];
	}

	int firNum, sec;
	for (int i = 1; i < K; ++i)
		if (a2i[i] != -1 && b2i[i] == -1)
		{
			firNum = i;
			sec = a2i[i];
			break;
		}

	for (int i = 0; i < n; ++i)
		if (a[i] == firNum)
		{
			sec = i;
			break;
		}

	answer[0] = firNum;
	curr = sec;
	for (int i = 1; i + 1 < n; i += 2)
	{
		answer[i + 1] = b[curr];
		curr = a2i[b[curr]];
	}

	for (int i = 0; i < n; ++i)
		std::cout << answer[i] << " ";
	std::cout << "\n";

	return 0;
}