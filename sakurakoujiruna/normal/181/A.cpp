#include <iostream>
using namespace std;

const int N = 121;
string mp[N];
int cr[N];
int cc[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		cin >> mp[i];
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(mp[i][j] == '*')
			{
				cr[i] ++;
				cc[j] ++;
			}
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(cr[i] == 1 && cc[j] == 1)
				cout << i + 1 << ' ' << j + 1 << '\n';
	return 0;
}