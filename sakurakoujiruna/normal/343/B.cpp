#include <iostream>
using namespace std;

const int N = 100011;

char sta[N];

int main()
{
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	/*
	if(n & 1)
		cout << "No\n";
	else
	{
		bool flag = false;
		for(int i = 0; i < n - 1; i ++)
			if(s[i] == s[i + 1])
				flag = true;
		if(flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	*/

	int top = 0;
	for(auto &c : s)
		if(top > 0 && sta[top - 1] == c)
			top --;
		else
			sta[top ++] = c;
	if(top == 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}