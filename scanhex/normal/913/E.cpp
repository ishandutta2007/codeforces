#include <bits/stdc++.h>

using namespace std;

typedef array<bool, 8> ar;

int toi(ar x)
{
	int ans = 0;
	for (auto y : x)
		ans *= 2, ans += y;
	return ans;
}

int main()
{
	vector<string> v = {"!x&x","x&y&z","!z&x&y","x&y","!y&x&z","x&z","!y&x&z|!z&x&y","(y|z)&x","!y&!z&x","!y&!z&x|x&y&z","!z&x","!z&x|x&y","!y&x","!y&x|x&z","!(y&z)&x","x","!x&y&z","y&z","!x&y&z|!z&x&y","(x|z)&y","!x&y&z|!y&x&z","(x|y)&z","!x&y&z|!y&x&z|!z&x&y","(x|y)&z|x&y","!x&y&z|!y&!z&x","!y&!z&x|y&z","!x&y&z|!z&x","!z&x|y&z","!x&y&z|!y&x","!y&x|y&z","!(y&z)&x|!x&y&z","x|y&z","!x&!z&y","!x&!z&y|x&y&z","!z&y","!z&y|x&y","!x&!z&y|!y&x&z","!x&!z&y|x&z","!y&x&z|!z&y","!z&y|x&z","!(!x&!y|x&y|z)","!(!x&!y|x&y|z)|x&y&z","!z&(x|y)","!z&(x|y)|x&y","!x&!z&y|!y&x","!x&!z&y|!y&x|x&z","!y&x|!z&y","!z&y|x","!x&y","!x&y|y&z","!(x&z)&y","y","!x&y|!y&x&z","!x&y|x&z","!(x&z)&y|!y&x&z","x&z|y","!x&y|!y&!z&x","!x&y|!y&!z&x|y&z","!x&y|!z&x","!z&x|y","!x&y|!y&x","!x&y|!y&x|x&z","!(x&z)&y|!y&x","x|y","!x&!y&z","!x&!y&z|x&y&z","!x&!y&z|!z&x&y","!x&!y&z|x&y","!y&z","!y&z|x&z","!y&z|!z&x&y","!y&z|x&y","!(!x&!z|x&z|y)","!(!x&!z|x&z|y)|x&y&z","!x&!y&z|!z&x","!x&!y&z|!z&x|x&y","!y&(x|z)","!y&(x|z)|x&z","!y&z|!z&x","!y&z|x","!x&z","!x&z|y&z","!x&z|!z&x&y","!x&z|x&y","!(x&y)&z","z","!(x&y)&z|!z&x&y","x&y|z","!x&z|!y&!z&x","!x&z|!y&!z&x|y&z","!x&z|!z&x","!x&z|!z&x|x&y","!x&z|!y&x","!y&x|z","!(x&y)&z|!z&x","x|z","!(!y&!z|x|y&z)","!(!y&!z|x|y&z)|x&y&z","!x&!y&z|!z&y","!x&!y&z|!z&y|x&y","!x&!z&y|!y&z","!x&!z&y|!y&z|x&z","!y&z|!z&y","!y&z|!z&y|x&y","!(!x&!y|x&y|z)|!x&!y&z","!(!x&!y|x&y|z)|!x&!y&z|x&y&z","!x&!y&z|!z&(x|y)","!x&!y&z|!z&(x|y)|x&y","!x&!z&y|!y&(x|z)","!x&!z&y|!y&(x|z)|x&z","!y&(x|z)|!z&y","!y&z|!z&y|x","!x&(y|z)","!x&(y|z)|y&z","!x&z|!z&y","!x&z|y","!x&y|!y&z","!x&y|z","!(x&y)&z|!z&y","y|z","!x&(y|z)|!y&!z&x","!x&(y|z)|!y&!z&x|y&z","!x&(y|z)|!z&x","!x&z|!z&x|y","!x&(y|z)|!y&x","!x&y|!y&x|z","!x&y|!y&z|!z&x","x|y|z","!(x|y|z)","!(x|y|z)|x&y&z","!(!x&y|!y&x|z)","!(x|y|z)|x&y","!(!x&z|!z&x|y)","!(x|y|z)|x&z","!(!x&y|!y&x|z)|!y&x&z","!(x|y|z)|(y|z)&x","!y&!z","!y&!z|x&y&z","!(!x&y|z)","!y&!z|x&y","!(!x&z|y)","!y&!z|x&z","!(!x&y|z)|!y&x","!y&!z|x","!(!y&z|!z&y|x)","!(x|y|z)|y&z","!(!x&y|!y&x|z)|!x&y&z","!(x|y|z)|(x|z)&y","!(!x&z|!z&x|y)|!x&y&z","!(x|y|z)|(x|y)&z","!(!x&y|!y&x|z)|!x&y&z|!y&x&z","!(x|y|z)|(x|y)&z|x&y","!x&y&z|!y&!z","!y&!z|y&z","!(!x&y|z)|!x&y&z","!(!x&y|z)|y&z","!(!x&z|y)|!x&y&z","!(!x&z|y)|y&z","!(!x&y|z)|!x&y&z|!y&x","!y&!z|x|y&z","!x&!z","!x&!z|x&y&z","!(!y&x|z)","!x&!z|x&y","!x&!z|!y&x&z","!x&!z|x&z","!(!y&x|z)|!y&x&z","!(!y&x|z)|x&z","!(x&y|z)","!(x&y|z)|x&y&z","!z","!z|x&y","!x&!z|!y&x","!(x&y|z)|x&z","!y&x|!z","!z|x","!(!y&z|x)","!x&!z|y&z","!(!y&x|z)|!x&y","!x&!z|y","!(!y&z|x)|!y&x&z","!(!y&z|x)|x&z","!(!y&x|z)|!x&y|!y&x&z","!x&!z|x&z|y","!x&y|!y&!z","!(x&y|z)|y&z","!x&y|!z","!z|y","!(!x&!y&z|x&y)","!x&!z|!y&x|y&z","!x&y|!y&x|!z","!z|x|y","!x&!y","!x&!y|x&y&z","!x&!y|!z&x&y","!x&!y|x&y","!(!z&x|y)","!x&!y|x&z","!(!z&x|y)|!z&x&y","!(!z&x|y)|x&y","!(x&z|y)","!(x&z|y)|x&y&z","!x&!y|!z&x","!(x&z|y)|x&y","!y","!y|x&z","!y|!z&x","!y|x","!(!z&y|x)","!x&!y|y&z","!(!z&y|x)|!z&x&y","!(!z&y|x)|x&y","!(!z&x|y)|!x&z","!x&!y|z","!(!z&x|y)|!x&z|!z&x&y","!x&!y|x&y|z","!x&z|!y&!z","!(x&z|y)|y&z","!(!x&!z&y|x&z)","!x&!y|!z&x|y&z","!x&z|!y","!y|z","!x&z|!y|!z&x","!y|x|z","!(x|y&z)","!(x|y&z)|x&y&z","!x&!y|!z&y","!(x|y&z)|x&y","!x&!z|!y&z","!(x|y&z)|x&z","!(!y&!z&x|y&z)","!x&!y|!z&y|x&z","!((x|y)&z|x&y)","!((x|y)&z|x&y)|x&y&z","!x&!y|!z","!x&!y|!z|x&y","!x&!z|!y","!x&!z|!y|x&z","!y|!z","!y|!z|x","!x","!x|y&z","!x|!z&y","!x|y","!x|!y&z","!x|z","!x|!y&z|!z&y","!x|y|z","!x|!y&!z","!x|!y&!z|y&z","!x|!z","!x|!z|y","!x|!y","!x|!y|z","!(x&y&z)","!x|x"};
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ar x;
		string s;
		cin >> s;
		for (int i = 0; i < 8; ++i)
			x[i] = s[i] - '0';
		cout << v[toi(x)] << '\n';
	}
}