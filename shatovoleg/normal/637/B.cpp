#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

int main()
{
	int sz;
	cin >> sz;
	map<string, int> chats;
	string a;
	for (int i = 0; i < sz; ++i)
	{
		cin >> a;
		chats[a] = i;
	}
	vector<pair<string, int>> res;
	for (map<string, int>::iterator it = chats.begin(); it != chats.end(); ++it)
		res.push_back(*it);
	sort(res.begin(), res.end(), cmp);
	for (auto &x : res)
		cout << x.first << endl;
}