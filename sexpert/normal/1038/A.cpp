#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	string s;
	map<char, int> mp;
	cin >> n >> k;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
	    mp[s[i]]++;
	}
	int num = 100000000;
	for(char c = 'A'; c < 'A' + k; c++)
	{
	    num = min(num, mp[c]);
	}
	cout << num*k << "\n";
}