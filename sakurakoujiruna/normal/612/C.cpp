#include <iostream>
using namespace std;

const int N = 1011111;

char sta[N];

int main()
{
	ios :: sync_with_stdio(false);
	string str;
	cin >> str;
	int top = 0;
	int ans = 0;
	bool flag = true;
	for(auto &c : str)
	{
		if(c == '(' || c == '<' || c == '{' || c == '[')
			sta[top ++] = c;
		else if(top == 0)
			flag = false;
		else
		{
			char t = sta[-- top];
			if((t == '(' && c != ')') ||
				(t == '<' && c != '>') ||
				(t == '{' && c != '}') ||
				(t == '[' && c != ']'))
				ans ++;
		}
	}
	if(flag && top == 0)
		cout << ans << '\n';
	else
		cout << "Impossible\n";
	return 0;
}