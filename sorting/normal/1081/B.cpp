#include <bits/stdc++.h>

const int N = 1e5 + 7;

int a[N];
int cnt[N];
std::vector<int> res;
int curr[N];
int which = 1;

int main ()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;

	std::cin >> n;

	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		a[i] = n - a[i];
		cnt[a[i]]++;
	}

	for(int i = 1; i <= n; i++)
		if(cnt[i] % i != 0)
		{
			std::cout << "Impossible\n";

			return 0;
		}

	std::cout << "Possible\n";


	for(int i = 0; i < n; i++)
	{
		if(cnt[a[i]] % a[i] == 0)
		{
			curr[a[i]] = which;
			which++;
			res.push_back(curr[a[i]]);
			cnt[a[i]]--;
		}
		else
		{
			res.push_back(curr[a[i]]);
			cnt[a[i]]--;
		}
	}

	for(int i = 0; i < res.size(); i++)
		std::cout << res[i] << " ";

	std::cout << "\n";

	return 0;
}