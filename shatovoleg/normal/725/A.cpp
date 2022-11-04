#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int idx = 0, cnt = 0;
	while (idx < n && s[idx] == '<')
	{
		++idx;
		++cnt;
	}
	idx = n - 1;
	while (idx >= 0 && s[idx] == '>')
	{
		--idx;
		++cnt;
	}
	cout << cnt << endl;
}