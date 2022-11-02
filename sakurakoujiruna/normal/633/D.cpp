#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 1011;
int num[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	map <int, int> cnt;
	for(int i = 0; i < n; i ++)
	{
		cin >> num[i];
		cnt[num[i]] ++;
	}
	int ans = 2;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(i != j)
			{
				//map <int, int> cnt = all;
				if(num[i] == 0 && num[j] == 0)
				{
					ans = max(ans, cnt[0]);
					continue;
				}
				cnt[num[i]] --;
				cnt[num[j]] --;
				vector <int> changes;
				changes.push_back(num[i]);
				changes.push_back(num[j]);
				/*
				if(num[i] == 0)
				{
					if(num[j] == 0)
						ans = max(ans, cnt[0] + 2);
					else
					{
						int c0 = cnt[0];
						int c1 = cnt[num[j]];
						if(c1 >= c0)
							ans = max(ans, c0 * 2 + 2);
						else
							ans = max(ans, c1 * 2 + 2 + 1);
					}
				}
				else
				*/
				{
					int acc = 2;
					int a = num[i];
					int b = num[j];
					while(true)
					{
						/*
						if(b == 0)
						{
							int c0 = cnt[0];
							int c1 = cnt[a];
							if(c0 >= c1)
								ans = max(ans, c1 * 2 + acc);
							else
								ans = max(ans, c0 * 2 + acc + 1);
							break;
						}
						*/
						int c = a + b;
						if(cnt[c] != 0)
						{
							acc ++;
							ans = max(ans, acc);
							cnt[c] --;
							changes.push_back(c);
							a = b;
							b = c;
						}
						else
							break;
					}
				}
				for(auto &c : changes)
					cnt[c] ++;
			}
	cout << ans << '\n';
	return 0;
}