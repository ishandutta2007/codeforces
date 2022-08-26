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

const int N = 5555;
const int INF = 0x3f3f3f3f;

int n, t[N];
std::vector < int > h[3];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w", stdout);

	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> t[i];
		--t[i];
		h[t[i]].push_back(i);
	}

	int a = 0;
	if (h[a].size() > h[1].size()) a = 1;
	if (h[a].size() > h[2].size()) a = 2;

	std::cout << h[a].size() << "\n";
	for (int i = 0; i < h[a].size(); ++i)
		std::cout << h[0][i] + 1 << " " << h[1][i] + 1 << " " << h[2][i] + 1 << "\n";
	return 0;
}