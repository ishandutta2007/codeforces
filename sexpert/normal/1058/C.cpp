#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int cumm;
	int sum = 0;
	bool flag = false;
	for(int i = 0; i < n; i++)
		sum += s[i] - '0';
	if(sum == 0)
		flag = true;
	for(int i = 1; i < sum; i++)
	{
		cumm = 0;
		if(sum % i) continue;
		for(int j = 0; j < n; j++)
		{
			cumm += s[j] - '0';
			if(cumm > i) break;
			if(cumm == i) cumm = 0;
			if(j == n - 1)
			{
				flag = true;
			}
		}
	}
	if(flag) cout << "YES\n";
	else cout << "NO\n";
}