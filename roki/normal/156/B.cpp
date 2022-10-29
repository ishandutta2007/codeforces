#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

int n, m;
int PlusC = 0, MinusC = 0;
char op[100000];
int to[100000];
int vote[100000], disvote[100000];
bool read()
{
	if (!(cin >> n >> m))
		return false;
	forn (i, n)
	{
		cin >> op[i] >> to[i];
		to[i]--;
		if (op[i] == '+')
			PlusC++, vote[to[i]]++;
		else
			MinusC++, disvote[to[i]]++;

	}
	return true;
}

void solve()    
{
	m = n - m;
	vector<bool> murder(n, false);
	int cnt = 0;
	forn (i, n)
		if (disvote[i] + PlusC - vote[i] == m)
			murder[i] = true, cnt++;

	forn (i, n)
	{
		if (disvote[i] + PlusC - vote[i] == m)
		{
			forn (j, n)
				if (op[j] == '+')
					if (murder[to[j]])
						if (cnt == 1)
							cout << "Truth" << endl;
						else
							cout << "Not defined" << endl;
					else
						cout << "Lie" << endl;
				else
					if (murder[to[j]])
						if (cnt == 1)
							cout << "Lie" << endl;
						else
							cout << "Not defined" << endl;
					else
						cout << "Truth" << endl;

		return;
		}
	}
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
	while (read())
		solve();
    return 0;
}