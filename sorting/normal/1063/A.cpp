#include<bits/stdc++.h>

using namespace std;

int arr[30];

int main ()
{
	string s;
	int n;

	cin >> n;

	cin >> s;

	for(int i = 0; i < s.size(); i++)
		arr[s[i] - 'a']++;

	sort(s.begin(), s.end());

	cout << s << endl;
	
	return 0;
}