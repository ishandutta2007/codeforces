#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;
const int MAXN = 3100;

struct blah
{
	string name;
	int nsee;
};

inline bool operator < (blah left, blah right)
{
	return left.nsee < right.nsee;
}

int n;
blah q[MAXN];
int hans[MAXN];

void ins (int pos, int val)
{
	for (int i = n - 1; i >= pos + 1; i--)
		hans[i] = hans[i-1];
	hans[pos] = val;
}

int find (int val)
{
	for (int i = 0; i < n; i++)
		if (hans[i] == val)
			return i;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> q[i].name >> q[i].nsee;
	sort (q, q + n);
	for (int i = 0; i < n; i++)
		hans[i] = 0;
	for (int i = 0; i < n; i++)
	{
		if (q[i].nsee > i)
		{
			cout << "-1\n";
			return 0;
		}
		ins (q[i].nsee, i);
	}
	for (int i = 0; i < n; i++)
		cout << q[i].name << " " << n - find (i) << "\n";
	return 0;
}