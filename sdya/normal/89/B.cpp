#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n;
struct widget
{
	int vbox, hbox;
	long long border, spacing;
	long long x, y;
	int num;
};

map < string, widget > MP; 
vector < int > g[1100];

char s[10000];
pair < string, widget > a[11000];

int ct = 0;

void new_widget(string s, int x, int y, int vbox = 0, int hbox = 0)
{
	widget A;
	A.vbox = vbox, A.hbox = hbox;
	A.border = 0, A.spacing = 0;
	A.x = x, A.y = y;
	ct ++;
	A.num = ct;

	a[ct] = make_pair(s, A);
	MP[s] = A;
}

void read()
{
	gets(s);
	int l = strlen(s);
	if (l >= 7)
	{
		string c = "";
		for (int i = 0; i < 7; i ++)
			c += s[i];
		if (c == "Widget ")
		{
			string name = "";
			for (int i = 7; i < l; i ++)
				if (s[i] == '(') break; else name += s[i];
			int x = 0, y = 0;
			for (int i = 7; i < l; i ++)
				if (s[i] == '(')
				{
					for (int j = i + 1; j < l; j ++)
						if (s[j] == ',') break; else x = x * 10 + (s[j] - '0');
				}
			for (int i = 7; i < l; i ++)
				if (s[i] == ',')
				{
					for (int j = i + 1; j < l; j ++)
						if (s[j] == ')') break; else y = y * 10 + (s[j] - '0');
				}
			new_widget(name, x, y);
			return ;
		}
	}
	if (l >= 5)
	{
		string c = "";
		for (int i = 0; i < 5; i ++)
			c += s[i];
		if (c == "VBox ")
		{
			string name = "";
			for (int i = 5; i < l; i ++)
				name += s[i];
			new_widget(name, 0, 0, 1, 0);
			return ;
		} else
		if (c == "HBox ")
		{
			string name = "";
			for (int i = 5; i < l; i ++)
				name += s[i];
			new_widget(name, 0, 0, 0, 1);
			return ;
		}
	}

	for (int i = 1; i < l; i ++)
		if (s[i - 1] == '.' && s[i] == 'p')
		{
			string s1 = "";
			for (int j = 0; j < i - 1; j ++)
				s1 += s[j];
			string s2 = "";
			for (int j = i + 5; j < l - 1; j ++)
				s2 += s[j];
			g[MP[s1].num].push_back(MP[s2].num);
			return ;
		} else
		if (s[i - 1] == '.' && s[i] == 's')
		{
			if (s[i + 4] == 'b')
			{
				string s1 = "";
				for (int j = 0; j < i - 1; j ++)
					s1 += s[j];
				int x = 0;
				for (int j = i + 11; j < l - 1; j ++)
					x = x * 10 + (s[j] - '0');
				widget A = MP[s1];
				A.border = x;
				MP[s1] = A;
				a[A.num] = make_pair(s1, A);
				return ;
			} else
			{
				string s1 = "";
				for (int j = 0; j < i - 1; j ++)
					s1 += s[j];
				int x = 0;
				for (int j = i + 12; j < l - 1; j ++)
					x = x * 10 + (s[j] - '0');
				widget A = MP[s1];
				A.spacing = x;
				MP[s1] = A;
				a[A.num] = make_pair(s1, A);
				return ;
			}
		}
}

bool used[1100];

void calc(int x)
{
	if (used[x]) return ;
	used[x] = true;

	for (int i = 0; i < g[x].size(); i ++)
		calc(g[x][i]);

	widget A = a[x].second;
	if (A.vbox == 0 && A.hbox == 0) return ;
	if (A.vbox == 1)
	{
		long long x0 = 0, y0 = 0;
		for (int i = 0; i < g[x].size(); i ++)
		{
			long long cx = a[g[x][i]].second.x, cy = a[g[x][i]].second.y;
			y0 += cy;
			x0 = max(x0, cx);
		}
		x0 += A.border * 2;
		y0 += A.border * 2;
		if (g[x].size() > 0) y0 += A.spacing * (g[x].size() - 1); else x0 = 0, y0 = 0;
		A.x = x0, A.y = y0;
		a[x].second = A;
		MP[a[x].first] = A;

		return ;
	} else
	if (A.hbox == 1)
	{
		long long x0 = 0, y0 = 0;
		for (int i = 0; i < g[x].size(); i ++)
		{
			long long cx = a[g[x][i]].second.x, cy = a[g[x][i]].second.y;
			x0 += cx;
			y0 = max(y0, cy);
		}
		x0 += A.border * 2;
		y0 += A.border * 2;
		if (g[x].size() > 0) x0 += A.spacing * (g[x].size() - 1); else x0 = 0, y0 = 0;
		A.x = x0, A.y = y0;
		a[x].second = A;
		MP[a[x].first] = A;
		return ;
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d\n", &n);
	for (int i = 0; i < n; i ++) read();

	for (int i = 1; i <= ct; i ++)
		if (!used[i]) calc(i);

	for (map < string, widget > :: iterator it = MP.begin(); it != MP.end(); it ++)
		cout << it->first << " " << it->second.x << " " << it->second.y << endl;
	return 0;
}