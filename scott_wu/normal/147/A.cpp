#include <iostream>
#include <iomanip>

using namespace std;
const int MAXL = 10100;

char s[MAXL];
char ans[2*MAXL];

int main()
{
	for (int i = 0; i < MAXL; i++)
		s[i] = 'A';
	cin.getline (s, MAXL - 1);
	int n;
	for (int i = 0; i < MAXL; i++)
	{
		if (s[i] == 'A')
		{
			n = i;
			break;
		}
	}
	n--;
	/*for (int i = 0; i < n; i++)
		cout << s[i];*/
	int cur = 0;
	int ncur = 0;
	//return 0;
	//cout << n << "\n";
	while (ncur < n)
	{
		while (s[ncur] == ' ' && ncur < n)
			ncur++;
		if (ncur == n) break;
		if (s[ncur] >= 'a' && s[ncur] <= 'z')
		{
			while (ncur < n && s[ncur] >= 'a' && s[ncur] <= 'z')
			{
				//cout << ncur << "\n";
				ans[cur] = s[ncur];
				cur++;
				ncur++;
			}
			while (ncur < n && s[ncur] == ' ')
				ncur++;
			if (ncur < n)
			{
				if (s[ncur] >= 'a' && s[ncur] <= 'z')
				{
					ans[cur] = ' ';
					cur++;
				}
				else
				{
					ans[cur] = s[ncur];
					cur++;
					ans[cur] = ' ';
					cur++;
					ncur++;
				}
			}
		}
		else
		{
			ans[cur] = s[ncur];
			cur++;
			ans[cur] = ' ';
			cur++;
			ncur++;
		}
	}
	for (int i = 0; i < cur; i++)
		cout << ans[i];
	cout << "\n";
	return 0;
}