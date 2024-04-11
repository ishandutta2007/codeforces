#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n, count = 0;
	pair<int, int> begin, pos, end;
	vector<pair<int, int> > obs;
	string mappings[] = {"ULDR", "ULRD", "URLD", "URDL", "UDLR", "UDRL", "LDRU", "LDUR", "LRUD", "LRDU", "LUDR", "LURD", "DRUL", "DRLU", "DULR", "DURL", "DLUR", "DLRU", "RULD", "RUDL", "RLDU", "RLUD", "RDUL", "RDLU"};
	string mapping, se, row;
	char step;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		cin >> row;
		for(int j = 0; j < m; j++)
		{
			if(row[j] == '#') obs.push_back(make_pair(j, i));
			if(row[j] == 'S') begin = pos = make_pair(j, i);
			if(row[j] == 'E') end = make_pair(j, i);
		}
	}
	cin >> se;
	for(int i = 0; i < 24; i++)
	{
		mapping = mappings[i];
		pos = begin;
		for(int j = 0; j < se.length(); j++)
		{
			step = mapping[int(se[j]) - 48];
			if(step == 'U') pos.second--;
			if(step == 'D') pos.second++;
			if(step == 'L') pos.first--;
			if(step == 'R') pos.first++;
			if(pos.first < 0 || pos.first > m - 1 || pos.second < 0 || pos.second > n - 1 || find(obs.begin(), obs.end(), pos) != obs.end()) break;
			if(pos == end)
			{
				count++;
				break;
			}
		}
	}
	printf("%d", count);
}