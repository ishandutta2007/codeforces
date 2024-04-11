#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct resident
{
	string name;
	int type, bonus, home, id;
	void read(int i);
};

resident a[1100];

struct sub
{
	string name;
	int type;
	int atk, def, res, size, id;
	vector < int > a;
	void read(int i);
	void print()
	{
		cout << name << " " << a.size() << " ";
		for (int i = 0; i < a.size(); i ++)
			cout << ::a[a[i]].name << " ";
		cout << endl;
	}
};

map < string, int > R;
map < string, int > S;


sub b[110];

int n, m;

int get(int u, int mode)
{
	int add = 0;
	for (int i = 0; i < b[u].a.size(); i ++)
	{
		int v = b[u].a[i];
		if (mode == a[v].type) add += a[v].bonus;
	}
	return add;
}

bool comp(int x, int y)
{
	return a[x].bonus > a[y].bonus;
}

vector < int > order;

void resident::read(int i)
{
	cin >> name;
	string s;
	cin >> s;
	if (s == "gladiator") type = 1; else
		if (s == "sentry") type = 2; else
			type = 3;
	cin >> bonus;
	cin >> s;
	home = S[s];
	R[name] = i;
	id = i;
	b[home].a.push_back(i);
}

void sub::read(int i)
{
	cin >> name;
	string s;
	cin >> s;
	if (s == "weapon") type = 1; else
		if (s == "armor") type = 2; else
			type = 3;
	cin >> atk >> def >> res >> size;
	S[name] = i;
	id = i;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		b[i].read(i);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++)
		a[i].read(i);

	bool good = true;
	for (int i = 1; i <= n; i ++)
		if (b[i].size != b[i].a.size()) good = false;
	if (good)
	{
		int x = -1, y = -1, z = -1, u = -1, v = -1, w = -1;
		for (int i = 1; i <= n; i ++)
			if (b[i].type == 1)
				for (int j = 1; j <= n; j ++)
					if (b[j].type == 2)
						for (int k = 1; k <= n; k ++)
							if (b[k].type == 3)
							{
								int s1 = b[i].atk + get(i, 1), s2 = b[j].def + get(j, 2), s3 = b[k].res + get(k, 3);
								if (make_pair(s1, make_pair(s2, s3)) > make_pair(x, make_pair(y, z)))
									x = s1, y = s2, z = s3, u = i, v = j, w = k;
							}
		b[u].print();
		b[v].print();
		b[w].print();
		return 0;
	} 

	for (int i = 1; i <= n; i ++)
	{
		order.clear();
		for (int j = 1; j <= m; j ++)
			if (a[j].type == b[i].type) order.push_back(j);
		sort(order.begin(), order.end(), comp);

		b[i].a.clear();
		for (int j = 0; j < min((int)order.size(), b[i].size); j ++)
			b[i].a.push_back(order[j]);
	}

	int x = -1, y = -1, z = -1, u = -1, v = -1, w = -1;
	for (int i = 1; i <= n; i ++)
		if (b[i].type == 1)
			for (int j = 1; j <= n; j ++)
				if (b[j].type == 2)
					for (int k = 1; k <= n; k ++)
						if (b[k].type == 3)
						{
							int s1 = b[i].atk + get(i, 1), s2 = b[j].def + get(j, 2), s3 = b[k].res + get(k, 3);
							if (make_pair(s1, make_pair(s2, s3)) > make_pair(x, make_pair(y, z)))
								x = s1, y = s2, z = s3, u = i, v = j, w = k;
						}
	for (int i = 0; i < b[u].a.size(); i ++)
	{
		int t = b[u].a[i];
		R.erase(a[t].name);
	}
	for (int i = 0; i < b[v].a.size(); i ++)
	{
		int t = b[v].a[i];
		R.erase(a[t].name);
	}
	for (int i = 0; i < b[w].a.size(); i ++)
	{
		int t = b[w].a[i];
		R.erase(a[t].name);
	}

	for (map < string, int > :: iterator it = R.begin(); it != R.end(); it ++)
	{
		int t = it->second;
		if (b[u].size > b[u].a.size()) b[u].a.push_back(t); else
			if (b[v].size > b[v].a.size()) b[v].a.push_back(t); else
				if (b[w].size > b[w].a.size()) b[w].a.push_back(t);
	}
	b[u].print();
	b[v].print();
	b[w].print();

	return 0;
}