#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

bool operator < (string a, string b)
{
	int n = min(a.size(), b.size());
	int i = 0;
	while (i < n && a[i] == b[i]) i++;
	if (i < n)
	{
		return a[i] < b[i];
	}
	return a.size() < b.size();
}

vector <string> s1[30];
vector <string> s2[30];
int k[30];
int u[30];
vector <pair <string, string> > ans;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		string x;
		cin >> x;
		s1[x[0] - 'A'].push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		string x;
		cin >> x;
		s2[x[0] - 'A'].push_back(x);
	}

	for (int i = 0; i < 30; i++)
	{
		sort(s1[i].begin(), s1[i].end());
		sort(s2[i].begin(), s2[i].end());
		k[i] = min(s1[i].size(), s2[i].size());
		u[i] = 0;
	}

	for (int i = 0; i < 30; i++)
	{
		int s = 0;
		bool f = false;
		for (int j = 0; j < s1[i].size() - k[i]; j++)
		{
			int l = 0;
			f = false;
			while (l < i)
			{
				if (u[l] + k[l] < s2[l].size())
				{
					//cout << s1[i][j] << " " << s2[l][u[l]] << endl;
					ans.push_back(make_pair(s1[i][j], s2[l][u[l]]));
					u[l]++;
					f = true;
					break;

				}
				l++;
			}
			if (f)
			{
				s++;
			}
			else
			{
				break;
			}
		}

		for (int j = u[i]; j < u[i] + k[i]; j++)
		{
			ans.push_back(make_pair(s1[i][j - u[i] + s], s2[i][j]));
			//cout << s1[i][j - u[i]] << " " << s2[i][j] << endl;
		}
		u[i] += k[i];
		int h = k[i];
		k[i] = 0;

		if (s1[i].size() > k[i] + s)
		{
			for (int j = h + s; j < s1[i].size(); j++)
			{
				int l = 0;
				while (l < 30)
				{
					if (u[l] + k[l] < s2[l].size())
					{
						//cout << s1[i][j] << " " << s2[l][u[l]] << endl;
						ans.push_back(make_pair(s1[i][j], s2[l][u[l]]));
						u[l]++;
						break;
					}
					l++;
				}
			}
		}
	}

	for (int i = 0; i < (int)ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second;
		if (i + 1 < (int)ans.size())
		{
			cout << ", ";
		}
	}



	return 0;
}