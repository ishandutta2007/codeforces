#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	map<char, int> count;
	bool flag = false;
	for(int i = 0; i < n; i++)
	{
	    char c = s[i];
	    count[c]++;
	    if(count[c] >= 2) flag = true;
	}
	if(flag || n == 1) cout << "Yes\n";
	else cout << "No\n";
}