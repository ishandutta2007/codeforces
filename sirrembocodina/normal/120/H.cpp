#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n;
int m[1000000], t[1000];
bool used[1000];
vector<string> s;

void read_info(){
	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
}

vector<vector<string> > r;
string cur = "";

void make(int p, int x){
	if (x == s[p].size()){
		if (cur.size() > 0 && cur.size() <= 4)
			r[p].pb(cur);
		return;
	}
	make(p, x+1);
	cur += s[p][x];
	make(p, x+1);
	cur = cur.substr(0, cur.size()-1);
}

void make_r(){
	r.resize(n);
	for (int i = 0; i < n; i++)
		make(i, 0);
}

vector<pair<string, int> > sarr;
vector<int> cl;
vector<string> ocl;
vector<pair<int, int> > g;
vector<vector<int> > gg;
int cnum = 0;

void make_sarr(){
	make_r();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < r[i].size(); j++)
			sarr.pb(mp(r[i][j], i));
	sort(sarr.begin(), sarr.end());
	cl.resize(sarr.size());
	cl[0] = cnum++;
	for (int i = 1; i < sarr.size(); i++)
		if (sarr[i-1].first == sarr[i].first)
			cl[i] = cnum - 1;
		else
			cl[i] = cnum++;
	for (int i = 0; i < sarr.size(); i++)
		g.pb(mp(sarr[i].second, cl[i]));
	ocl.resize(cnum);
	for (int i = 0; i < sarr.size(); i++)
		ocl[cl[i]] = sarr[i].first;
	gg.resize(n);
	for (int i = 0; i < g.size(); i++)
		gg[g[i].first].pb(g[i].second);
	/*for (int i = 0; i < sarr.size(); i++)
		cout << sarr[i].first << ' ' << sarr[i].second << ' ' << cl[i] << endl;*/
}
bool dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < gg[v].size(); i++)
	{
		int u = gg[v][i];
		if ((m[u] != -1) && (used[m[u]]))
			continue;
		if ((m[u] == -1) || (dfs(m[u])))
		{
			m[u] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	read_info();
	make_sarr();
	for (int i = 0; i < cnum; i++)
		m[i] = -1;
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			used[j] = false;
		r += dfs(i) ? 1 : 0;
	}
	for (int i = 0; i < cnum; i++)
		if (m[i] != -1)
			t[m[i]] = i;
	if (r < n)
		cout << "-1";
	else
	{
		for (int i = 0; i < n; i++)
			cout << ocl[t[i]] << endl;
	}
    return 0;
}