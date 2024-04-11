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

const int N = 1005005;
const int INF = 0x3f3f3f3f;

std::string n;
ll a, b, ca, cb;
ll pow10modB[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w", stdout);

	std::cin >> n >> a >> b;
	pow10modB[0] = 1;
	for (int i = 1; i < N; ++i)
		pow10modB[i] = (pow10modB[i - 1] * 10) % b;
	for (int i = 0; i < n.size(); ++i)
		(cb += (n[i] - '0') * pow10modB[n.size() - i - 1]) %= b;

	for (int i = 0; i < n.size() - 1; ++i)
	{
		(ca *= 10) %= a;
		(ca += n[i] - '0') %= a;
		cb = (b * 10 + cb - (n[i] - '0') * pow10modB[n.size() - 1 - i]) % b;
		if (ca == 0 && cb == 0 && n[i + 1] != '0')
		{
			std::cout << "YES\n" << n.substr(0, i + 1) << "\n" << n.substr(i + 1, n.size() - i - 1) << "\n";
			return 0;
		}
	}

	std::cout << "NO\n";

	return 0;
}