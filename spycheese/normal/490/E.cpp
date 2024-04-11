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

const int N = 100500;
const int INF = 0x3f3f3f3f;

int n;
std::string answer[N];

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w", stdout);

	std::cin >> n;
	std::string prev = "00000000";
	for (int i = 0; i < n; ++i)
	{
		answer[i] = "99999999";
		std::string a;
		std::cin >> a;
		std::reverse(a.begin(), a.end());
		int add0 = 0;
		while (a.size() < 8)
		{
			a += '0';
			++add0;
		}
		std::reverse(a.begin(), a.end());

		std::vector < int > qs;
		for (int j = 0; j < 8; ++j)
			if (a[j] == '?')
				qs.push_back(j);

		std::string na = a;
		bool ok = false;
		for (int j = qs.size(); j >= 0; --j)
		{
			bool fail = false;
			for (int k = 0; k < j; ++k)
			{
				na[qs[k]] = prev[qs[k]];
				if (qs[k] == add0 && prev[qs[k]] == '0')
				{
					fail = true;
					break;
				}
			}
			if (fail) continue;
			if (j != qs.size())
			{
				if (prev[qs[j]] == '9')
					continue;
				na[qs[j]] = prev[qs[j]] + 1;
			}
			for (int k = j + 1; k < qs.size(); ++k)
			{
				na[qs[k]] = '0';
				if (qs[k] == add0)
				{
					fail = true;
					break;
				}
			}
			if (fail) continue;
			if (na > prev)
			{
				ok = true;
				answer[i] = std::min(answer[i], na);
				break;
			}
		}
		for (int j = qs.size() - 1; j >= 0; --j)
		{
			bool fail = false;
			for (int k = 0; k < j; ++k)
			{
				na[qs[k]] = prev[qs[k]];
				if (qs[k] == add0 && prev[qs[k]] == '0')
				{
					fail = true;
					break;
				}
			}
			if (fail) continue;
			for (int k = j; k < qs.size(); ++k)
			{
				na[qs[k]] = '0';
				if (qs[k] == add0)
				{
					fail = true;
					break;
				}
			}
			if (fail) continue;
			if (na > prev)
			{
				ok = true;
				answer[i] = std::min(answer[i], na);
			}
		}
		if (!ok)
		{
			std::cout << "NO\n";
			return 0;
		}
		prev = answer[i];
		answer[i] = answer[i].substr(add0, 8 - add0);
	}

	std::cout << "YES\n";
	for (int i = 0; i < n; ++i)
		std::cout << answer[i] << "\n";

	return 0;
}