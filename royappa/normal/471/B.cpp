#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>


//http://codeforces.com/contest/471/problem/0

using namespace std;


typedef long long LL;

void outvec(vector<int> v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		cout << v[i];
		if (i != n-1)
			cout << " ";
	}
	cout << endl;
}

void selsort(vector<int>& a, vector<int>& b)
{
	int n = a.size();
	for (int i = 0; i < n-1; i++)
	{
		int m = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[m])
			{
				m = j;
			}
		}
		swap(a[i], a[m]);
		swap(b[i], b[m]);
	}
}

void genplan3(vector<int> v, int p3, vector<int> ind)
{
	int n = v.size();
	vector<int> w;
	selsort(v, ind);
	for (int i = 0; i < n; i++)
	{
		if (v[i] == p3 && w.size() < 3)
		{
			w.push_back(i);
		}
	}
	outvec(ind);
	swap(ind[w[0]], ind[w[1]]);
	outvec(ind);
	swap(ind[w[1]], ind[w[2]]);
	outvec(ind);
}

void genplan2(vector<int> v, vector<int> h, vector<int> ind)
{
	int n = v.size();
	selsort(v, ind);
	vector<int> w;
	for (int i = 1; i <= 2000; i++)
	{
		if (h[i] == 2 && w.size() < 4)
		{
			for (int j = 0; j < n; j++)
			{
				if (v[j] == i && w.size() < 4)
				{
					w.push_back(j);
				}
			}
		}
	}
	outvec(ind);
	swap(ind[w[0]], ind[w[1]]);
	outvec(ind);
	swap(ind[w[2]], ind[w[3]]);
	outvec(ind);
}

int main()
{
	int n;
	vector<int> h(2001, 0);

	cin >> n;
	vector<int> v(n, 0);
	vector<int> ind;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		ind.push_back(i+1);
		h[v[i]]++;
	}
	int m = 1;
	for (int i = 1; i <= 2000; i++)
	{
		if (h[i] > 0)
		{
			m *= h[i];
		}
		if (m > 3)
		{
			break;
		}
	}
	if (m < 3)
	{
		cout << "NO" << endl;
		exit(0);
	}
	cout << "YES" << endl;
	// make 3 distinct plans
	int p3 = -1;
	for (int i = 1; i <= 2000; i++)
	{
		if (h[i] >= 3)
		{
			p3 = i;
			break;
		}
	}
	if (p3 != -1)
	{
		genplan3(v, p3, ind);
		exit(0);
	}
	// otherwise there have to be at least two 2's
	genplan2(v, h, ind);
	exit(0);
}