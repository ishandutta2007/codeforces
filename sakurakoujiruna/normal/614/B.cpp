#include <iostream>
using namespace std;

int check(string &str)
{
	if(str[0] == '0')
		return -2;
	int cnt = 0;
	for(auto &chr : str)
		if(chr == '1')
			cnt ++;
		else if(chr != '0')
			cnt += 2;
	if(cnt > 1)
		return -1;
	return str.length() - 1;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;

	int len = 0;
	string save = "1";
	for(int i = 0; i < n; i ++)
	{
		string str;
		cin >> str;
		int c = check(str);
		if(c == -2)
		{
			cout << 0 << '\n';
			return 0;
		}
		else if(c == -1)
			save = str;
		else
			len += c;
	}
	cout << save;
	for(int i = 0; i < len; i ++)
		cout << 0;
	cout << '\n';
	return 0;
}