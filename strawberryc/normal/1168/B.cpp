#include <bits/stdc++.h>

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 3e5 + 5;

int n;
char s[N];
ll ans;

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		int id = 0, st = Max(1, i - 25);
		for (int j = st; j <= i; j++)
			for (int k = j + 2; k <= i; k += 2)
				if (s[j] == s[k] && s[j] == s[j + k >> 1])
					id = Max(id, j);
		ans += id;
	}
	return std::cout << ans << std::endl, 0;
}