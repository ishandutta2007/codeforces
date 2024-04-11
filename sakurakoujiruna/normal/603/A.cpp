#include <iostream>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	string str;
	cin >> str;
	int ans = 0;
	for(int i = 0; i < n; i ++)
		if(i == 0 || str[i] != str[i - 1])
			ans ++;

	int cnt = 0;
	for(int i = 0; i < n - 1; i ++)
		if((str[i] == '0' && str[i + 1] == '0')
			|| (str[i] == '1' && str[i + 1] == '1'))
			cnt ++;
	if(cnt > 2)
		cnt = 2;
	cout << ans + cnt << '\n';
	return 0;
}