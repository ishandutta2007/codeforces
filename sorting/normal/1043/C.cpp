#include<bits/stdc++.h>

using namespace std;

int res[1001];

int main ()
{
	string s;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'a')
			res[i]++;

		if(i != s.size()-1 && s[i+1] == 'a')
			res[i] = 1 - res[i];
	}

	for(int i = 0; i < s.size(); i++)
		cout << res[i] << " ";

	cout << "\n";
}