#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define s second
#define f first
#define ull unsigned long long
#define ll long long

const int nmax = 3 * (int)1e5 + 10, inf = (int)1e9 + 7;

map < int, vector < int > > M;
long long pls[nmax], minus[nmax], a[nmax], L, R, Ans = -(ll)1e15;
int was[nmax], del, n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		M[a[i]].push_back(i);
	}
	for(int i = 0; i < n; ++i)
		if(a[i] >= 0)
			pls[i] = (i > 0 ? pls[i - 1] : 0) + a[i];
		else
			pls[i] = (i > 0 ? pls[i - 1] : 0);
	for(map < int, vector < int > > :: iterator it = M.begin(); it != M.end(); ++it)
		if(it->second.size() > 1)
		{
			int l = it->second[0], r = it->second[it->second.size() - 1];
			if(pls[r - 1] - pls[l] + a[l] + a[r] > Ans)
			{
				Ans = pls[r - 1] - pls[l] + a[l] + a[r];
				L = l, R = r;
			}
		}
	for(int i = 0; i < L; ++i)
		++del, was[i] = 1;
	for(int i = R + 1; i < n; ++i)
		++del, was[i] = 1;
	for(int i = L + 1; i < R; ++i)
		if(a[i] < 0)
			++del, was[i] = 1;
	cout << Ans << " " << del << endl;
	for(int i = 0; i < n; ++i)
		if(was[i])
			cout << i + 1 << " ";
}