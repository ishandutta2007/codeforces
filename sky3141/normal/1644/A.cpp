#include<iostream>

using namespace std;

string s;
int t;
bool flag[4];

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> s;
		flag[0] = 0; flag[1] = 0; flag[2] = 0;
		for(int i = 0; i <= 5; i++)
		{
			if(s[i] == 'r') flag[0] = 1;
			if(s[i] == 'g') flag[1] = 1;
			if(s[i] == 'b') flag[2] = 1;
			if(s[i] == 'R' && !flag[0])
			{
				cout << "NO" << endl;
				break;
			}
			if(s[i] == 'G' && !flag[1])
			{
				cout << "NO" << endl;
				break;
			}
			if(s[i] == 'B' && !flag[2])
			{
				cout << "NO" << endl;
				break;
			}
			if(i == 5) cout << "YES" << endl;
		}
	}
	
	return 0;
}