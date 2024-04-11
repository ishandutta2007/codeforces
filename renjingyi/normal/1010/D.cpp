#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 1e6 + 5;
int type[maxn];
int s1[maxn], s2[maxn];
bool v[maxn];
bool ans[maxn];
void getv(const int &p)
{
	if(!type[p])
		return;
	if(type[p] == 1)
	{
		getv(s1[p]);
		getv(s2[p]);
		v[p] = v[s1[p]] & v[s2[p]];
	}
	else if(type[p] == 2)
	{
		getv(s1[p]);
		getv(s2[p]);
		v[p] = v[s1[p]] | v[s2[p]];
	}
	else if(type[p] == 3)
	{
		getv(s1[p]);
		getv(s2[p]);
		v[p] = v[s1[p]] ^ v[s2[p]];
	}
	else if(type[p] == 4)
	{
		getv(s1[p]);
		v[p] = !v[s1[p]];
	}
}
void getans(const int &p, const bool &v0, const bool &v1)
{
	if(!type[p])
	{
		if(v[p])
			ans[p] = v0;
		else
			ans[p] = v1;
		return;
	}
	if(type[p] == 1)
	{
		if(v[p] == 1)
		{
			getans(s1[p], v0, v1);
			getans(s2[p], v0, v1);
		}
		else if(v[p] == 0 && v[s1[p]] == 1)
		{
			getans(s1[p], v0, v0);
			getans(s2[p], v0, v1);
		}
		else if(v[p] == 0 && v[s2[p]] == 1)
		{
			getans(s1[p], v0, v1);
			getans(s2[p], v0, v0);
		}
		else
		{
			getans(s1[p], v0, v0);
			getans(s2[p], v0, v0);
		}
	}
	else if(type[p] == 2)
	{
		if(v[p] == 0)
		{
			getans(s1[p], v0, v1);
			getans(s2[p], v0, v1);
		}
		else if(v[p] == 1 && v[s1[p]] == 0)
		{
			getans(s1[p], v1, v1);
			getans(s2[p], v0, v1);
		}
		else if(v[p] == 1 && v[s2[p]] == 0)
		{
			getans(s1[p], v0, v1);
			getans(s2[p], v1, v1);
		}
		else
		{
			getans(s1[p], v1, v1);
			getans(s2[p], v1, v1);
		}
	}
	else if(type[p] == 3)
	{
		if(v[p] == 0 && v[s1[p]] == 0)
		{
			getans(s1[p], v0, v1);
			getans(s2[p], v0, v1);
		}
		else if(v[p] == 0)
		{
			getans(s1[p], v1, v0);
			getans(s2[p], v1, v0);
		}
		else if(v[p] == 1 && v[s1[p]] == 0)
		{
			getans(s1[p], v1, v0);
			getans(s2[p], v0, v1);
		}
		else
		{
			getans(s1[p], v0, v1);
			getans(s2[p], v1, v0);
		}
	}
	else if(type[p] == 4)
		getans(s1[p], v1, v0);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		string s;
		cin >> s;
		if(s == "AND")
		{
			type[i] = 1;
			cin >> s1[i] >> s2[i];
		}
		else if(s == "OR")
		{
			type[i] = 2;
			cin >> s1[i] >> s2[i];
		}
		else if(s == "XOR")
		{
			type[i] = 3;
			cin >> s1[i] >> s2[i];
		}
		else if(s == "NOT")
		{
			type[i] = 4;
			cin >> s1[i];
		}
		else if(s == "IN")
			cin >> v[i];
	}
	getv(1);
	getans(1, 0, 1);
	for(int i = 1; i <= n; i ++)
		if(!type[i])
			cout << ans[i];
	cout << endl;
	
	return 0;
}