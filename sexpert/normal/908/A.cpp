#include <bits/stdc++.h>
using namespace std;

int main()
{
	int count = 0;
	char let;
	char c[] = {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		let = s[i];
		for(int j = 0; j < 10; j++)
		{
			if(let == c[j]) count++;
		}
	}
	printf("%d", count);
}