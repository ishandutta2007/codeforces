#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 200011;
string s1, s2;
bool c(int l1, int r1, int l2, int r2)
{
	for(int i = 0; i < r1 - l1; i ++)
		if(s1[i + l1] != s2[i + l2])
			return false;
	return true;
}
bool check(int l1, int r1, int l2, int r2)
{
	if((r1 - l1) & 1)
		return c(l1, r1, l2, r2);
	int mid1 = (l1 + r1) / 2;
	int mid2 = (l2 + r2) / 2;
	if(rand() & 1)
	{
		if(check(l1, mid1, l2, mid2))
			if(check(mid1, r1, mid2, r2))
				return true;
		return check(l1, mid1, mid2, r2) && check(mid1, r1, l2, mid2);
	}
	else
	{
		if(check(l1, mid1, mid2, r2))
			if(check(mid1, r1, l2, mid2))
				return true;
		return check(l1, mid1, l2, mid2) && check(mid1, r1, mid2, r2);
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	srand(233);
	cin >> s1 >> s2;
	int n = s1.size();
	if(check(0, n, 0, n))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}