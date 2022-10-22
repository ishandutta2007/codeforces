#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

const int C = 26;

struct nd
{
	nd* go[C];
	vector<int> mem;
	nd(){
		fill(go, go + C, nullptr);
	}
};

vector<int> pref(string s)
{
	vector<int> ans(s.size() + 1);
	for (int i = 2; i <= s.size(); ++i)
	{
		int j = ans[i - 1];
		while (j > 0 && s[j] != s[i - 1])
			j = ans[j];
		if (s[j] == s[i - 1])
			++j;
		ans[i] = j;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	const int BL = 30;
	nd* rt = new nd;
	for (auto& x : s)
		x -= 'a';
	vector<nd*> vert;
	for (int i = 0; i < s.size(); ++i)
	{
		nd* cur = rt;
		for (int j = 0; j < BL && i + j < s.size(); ++j)
		{
			if (cur->go[s[i + j]] == 0)
			{
				nd* nw = new nd;
				cur->go[s[i + j]] = nw;
				vert.push_back(nw);
			}
			cur = cur->go[s[i + j]];
			cur->mem.push_back(i);
		}
	}
	int n;
	cin >> n;
	while (n--)
	{
		int k;
		string m;
		cin >> k >> m;
		for (auto& x : m)
			x -= 'a';
		vector<int> arr;
		if (m.size() < BL)
		{
			nd* cur = rt;
			bool ok = true;
			for (char ch : m)
			{
				if (!cur->go[ch])
				{
					ok = false;
					break;
				}
				cur = cur->go[ch];
			}
			if (!ok)
			{
				cout << -1 << '\n';
				continue;
			}
			arr = cur->mem;
		}
		else
		{
			string s1 = m + "#" + s;
			auto kek = pref(s1);
			for (int i = 0; i + m.size() <= s.size(); ++i)
				if (kek[m.size() + 1 + i + m.size()] >= m.size())
					arr.push_back(i);
		}
		/*
		if (1)
		{
			string s1 = s;
			for (auto& x : s1)
				x += 'a';
			for (auto& x : arr)
			{
				cout << s1.substr(x, m.size()) << '\n';
			}
		}
		*/
		int oo = 1e9;
		int ans = oo;
		for (int i = 0; i + k <= arr.size(); ++i)
		{
			ans = min(ans, arr[i + k - 1] - arr[i]);
		}
		if (ans == oo)
			cout << -1 << '\n';
		else
			cout << ans + m.size() << '\n';
	}
	return 0;
}