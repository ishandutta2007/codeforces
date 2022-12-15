#include<bits/stdc++.h>

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	string s;

	cin >> s;

	for(int i = 0; i < n-1; i++)
		if(s[i+1] < s[i])
		{
			s.erase(i, 1);

			cout << s << "\n";

			return 0;
		}

	s.erase(n-1, 1);

	cout << s << "\n";

	return 0;
}