#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b, c;
	int am[27][2];
	cin >> a >> b >> c;
	for (int i = 0; i < 27; i++)
		am[i][0] = am[i][1] = 0;
	for (int i = 0; i < a.length(); i++)
		am[(int)a[i]-'A'][0]++;
	for (int i = 0; i < b.length(); i++)
		am[(int)b[i]-'A'][0]++;
	for (int i = 0; i < c.length(); i++)
		am[(int)c[i]-'A'][1]++;
	for (int i = 0; i < 27; i++)
	{
		if (am[i][0] != am[i][1])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}