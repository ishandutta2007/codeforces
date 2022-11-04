#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> arr(n);
	vector<pair<char, char>> chr(26, make_pair('\0', '\0'));
	vector<bool> was(26, false);
#define next second
#define prev first
	for (int i = 0; i < arr.size(); ++i)
		cin >> arr[i];
	for (auto x : arr)
	{
		for (int i = 0; i < x.length() - 1; ++i)
			chr[x[i] - 'a'].next = x[i + 1];
		for (int i = 1; i < x.length(); ++i)
			chr[x[i] - 'a'].prev = x[i - 1];
		for (auto y : x)
			was[y - 'a'] = true;
	}
	string res;
	for (int i = 0; i < 26; ++i)
	if (chr[i].prev == '\0' && was[i])
	{
		int iter = i;
		while (chr[iter].next != '\0')
		{
			was[iter] = false;
			res.push_back(iter + 'a');
			iter = chr[iter].next - 'a';
		}
		was[iter] = false;
		res.push_back(iter + 'a');
	}
	cout << res;
}