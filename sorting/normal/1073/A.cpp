#include<bits/stdc++.h>

using namespace std;

int main ()
{
	string s;
	int n;

	cin >> n;

	cin >> s;

	for(int i = 0; i < s.size()-1; i++)
		if(s[i] != s[i+1])
		{
			cout << "YES\n";
			cout << s[i] << s[i+1] << "\n";
			return 0;
		}

	cout << "NO\n";

	return 0;
}