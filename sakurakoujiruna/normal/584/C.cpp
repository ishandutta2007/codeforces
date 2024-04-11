#include <iostream>
using namespace std;

char get_diff(char c1, char c2)
{
	if(c1 == 'a' || c2 == 'a')
		if(c1 == 'b' || c2 == 'b')
			return 'c';
		else
			return 'b';
	else
		return 'a';
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, t;
	cin >> n >> t;

	string s1, s2;
	cin >> s1 >> s2;

	int same_cnt = 0;
	int diff_cnt = 0;
	for(int i = 0; i < n; i ++)
		if(s1[i] == s2[i])
			same_cnt ++;
		else
			diff_cnt ++;

	int range_a = diff_cnt / 2;
	int range_c = same_cnt;

	if(range_a + range_c < n - t)
		cout << -1 << '\n';
	else
	{
		int a = 0;
		int c = 0;
		if(n - t > same_cnt)
		{
			c = same_cnt;
			a = n - t - c;
		}
		else
		{
			c = n - t;
			a = 0;
		}

		string ans;
		for(int i = 0; i < n; i ++)
			if(s1[i] == s2[i])
			{
				if(same_cnt <= c)
					ans += s1[i];
				else
					ans += get_diff(s1[i], s2[i]);
				same_cnt --;
			}
			else
			{
				if(diff_cnt <= a)
					ans += s1[i];
				else if(diff_cnt <= 2 * a)
					ans += s2[i];
				else
					ans += get_diff(s1[i], s2[i]);
				diff_cnt --;
			}

		cout << ans << '\n';
	}
	return 0;
}