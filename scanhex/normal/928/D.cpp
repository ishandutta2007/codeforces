#include <bits/stdc++.h>

using namespace std;

const int C = 26;

vector<vector<int>> go(1, vector<int>(C, -1));

vector<string> strs;

vector<vector<int>> cnt(1);
set<string> st;

void add(string s)
{
	int cur = 0;
	bool nw = !st.count(s);
	st.insert(s);
	for (char ch : s)
	{
		ch -= 'a';
		if (go[cur][ch] == -1)
		{
			go.push_back(vector<int>(C, -1));
			cnt.push_back(vector<int>());
			go[cur][ch] = go.size() - 1;
		}
		cur = go[cur][ch];
		if (nw)
			cnt[cur].push_back(strs.size());
	}
	if (nw)
		strs.push_back(s);
}

int get(string s)
{
	int cur = 0;
	int d = 0;
	for (char ch : s)
	{
		ch -= 'a';
		if (go[cur][ch] == -1)
			return 1e9;
		cur = go[cur][ch];
		++d;
		if (cnt[cur].size() == 1)
		{
			string& s1 = strs[cnt[cur][0]];
			if (s1.size() > s.size() || s.substr(0, s1.size()) != s1)
				return 1e9;
			return d + 1 + s.size() - strs[cnt[cur][0]].size();
		}
	}
	return 1e9;
}

int main()
{
	string s;
	int ans = 0;
	while (getline(cin, s))
	{
		s.push_back('\n');
		string word;
		for (char ch : s)
		{
			if ('a' <= ch && ch <= 'z')
				word.push_back(ch);
			else
			{
				++ans;
				if (word.size())
				{
					int mem = get(word);
//					cerr << word << ' ' << mem << '\n';
					ans += min((int)word.size(), mem);
					add(word);
					word.clear();
				}
			}
		}
	}
	cout << ans << '\n';
}