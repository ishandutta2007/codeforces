#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 5100;

int N, M;
int arr[MAXN];
int lim[MAXN];

int tval[MAXN], lval[MAXN], rval[MAXN], dval[MAXN];

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		arr[i] = 0;
		lim[i] = 5e8;
	}
	
	for (int i = 0; i < M; i++)
	{
		int t, l, r, d;
		cin >> t >> l >> r >> d;
		
		l--, r--;
		
		if (t == 1)
		{
			for (int j = l; j <= r; j++)
				arr[j] += d;
		}
		else
		{
			for (int j = l; j <= r; j++)
				lim[j] = min (lim[j], d - arr[j]);
		}
		
		tval[i] = t;
		lval[i] = l;
		rval[i] = r;
		dval[i] = d;
	}
	
	bool works = true;
	for (int i = 0; i < N; i++)
		arr[i] = lim[i];
	
	for (int i = 0; i < M; i++)
	{
		int t = tval[i], l = lval[i], r = rval[i], d = dval[i];
		
		if (t == 1)
		{
			for (int j = l; j <= r; j++)
				arr[j] += d;
		}
		else
		{
			bool good = false;
			for (int j = l; j <= r; j++)
				if (arr[j] == d)
					good = true;
			if (!good) works = false;
		}
	}
	
	if (works)
	{
		cout << "YES\n";
		for (int i = 0; i < N; i++)
		{
			cout << lim[i];
			if (i < N - 1)
				cout << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}