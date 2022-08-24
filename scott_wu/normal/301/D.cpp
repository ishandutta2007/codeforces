#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
const int MAXN = 200100;
const int MAXP = (1 << 20) + 100;

int N, M;
int loc[MAXN];
int arr[MAXN];
int tot;

int P, ndig;
int num[MAXP];

int qleft[MAXN], qright[MAXN];
vector <pair <int, int> > qposs[MAXN];

vector <int> edge[MAXN]; // connects only to values < it
int ares[MAXN];

int nstart[MAXN], nend[MAXN];
int pstart[MAXN], pend[MAXN];

void add (int left, int right) // left < right
{
	edge[max (loc[right], loc[left])].push_back (min (loc[right], loc[left]));
}

void ins (int x)
{
	x += P;
	
	while (x)
	{
		num[x]++;
		x /= 2;
	}
}

int query (int x)
{
	if (x == 0) return 0;
	
	int cloc = 1;
	int sum = 0;
	
	for (int i = 0; i < ndig; i++)
	{
		if (x & (1 << (ndig - 1 - i)))
		{
			sum += num[2*cloc];
			cloc = 2 * cloc + 1;
		}
		else
			cloc *= 2;
	}
	return sum;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		loc[arr[i]] = i;
	}
	
	tot = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				add (j, i);
				tot++;
				
				if (j * j != i)
				{
					add (i / j, i);
					tot++;
				}
			}
		}
	}
	
	for (int i = 0; i < M; i++)
	{
		cin >> qleft[i] >> qright[i];
		qleft[i]--, qright[i]--;
		
		qposs[qright[i]].push_back (make_pair (qleft[i], i));
	}
	
	P = 1 << 19;
	ndig = 19;
	
	for (int i = 0; i < MAXP; i++)
		num[i] = 0;
	
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < qposs[i].size(); j++)
			ares[qposs[i][j].second] = query (qposs[i][j].first);
		
		for (int j = 0; j < edge[i].size(); j++)
			ins (edge[i][j]);
	}
	
	for (int i = 0; i < MAXN; i++)
		nstart[i] = nend[i] = pstart[i] = pend[i] = 0;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < edge[i].size(); j++)
		{
			nstart[edge[i][j]]++;
			//if (edge[i][j] == 0)
			//	cout << i << "\n";
			nend[i]++;
		}
	
	for (int i = 0; i < N; i++)
		pend[i+1] = pend[i] + nend[i];
	for (int i = N - 1; i >= 0; i--)
		pstart[i] = pstart[i+1] + nstart[i];
	
	for (int i = 0; i < M; i++)
	{
		//cout << pstart[qleft[i]] << " " << pend[qright[i]+1] << " " << ares[i] << " " << tot << "\n";
		cout << pstart[qleft[i]] + pend[qright[i]+1] + ares[i] - tot << "\n";
	}
	return 0;
}