#include <iostream>
using namespace std;

char c1[4];
char c2[4];

int main()
{
	ios :: sync_with_stdio(false);
	cin >> c1[0] >> c1[1] >> c1[3] >> c1[2];
	cin >> c2[0] >> c2[1] >> c2[3] >> c2[2];
	for(int i = 0; i < 4; i ++)
		if(c1[i] == 'X')
		{
			for(int j = i; j < 4 - 1; j ++)
				c1[j] = c1[j + 1];
			break;
		}
	for(int i = 0; i < 4; i ++)
		if(c2[i] == 'X')
		{
			for(int j = i; j < 4 - 1; j ++)
				c2[j] = c2[j + 1];
			break;
		}
	bool flag = false;
	for(int shift = 0; shift < 3; shift ++)
	{
		bool tmp = true;
		for(int i = 0; i < 3; i ++)
			if(c1[i] != c2[(i + shift) % 3])
				tmp = false;
		flag |= tmp;
	}
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}