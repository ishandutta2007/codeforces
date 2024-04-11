#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, M; // N = fox size, M = cat size
int fox[MAXN];
int cat[MAXN];
string str1, str2;
int lo, hi;

int np[3][3]; //# of consec pairs[i][j] in current range

void ihi()
{
	np[cat[hi]][cat[hi+1]]++;
	hi++;
}

void ilo()
{
	np[cat[lo]][cat[lo+1]]--;
	lo++;
}

int pchar (char ch)
{
	if (ch == 'R') return 0;
	if (ch == 'G') return 1;
	return 2;
}

int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			np[i][j] = 0;
	
	cin >> str1 >> str2;
	N = str1.length();
	M = str2.length();
	
	for (int i = 0; i < N; i++)
		fox[i] = pchar (str1[i]);
	for (int i = 0; i < M; i++)
		cat[i] = pchar (str2[i]);
	
	lo = 0, hi = 0; // values on cat range
	while (hi < M - 1 && cat[hi] != fox[0])
		ihi();
	
	ll ans = hi + 1;
	for (int i = 1; i < N; i++)
	{
		int lval = fox[i-1], cval = fox[i];
		
		if (cat[lo] == lval && lo >= M - 1)
			break;
		
		if (cat[hi] == lval && hi < M - 1)
			ihi();
		if (cat[lo] == lval)
			ilo();
		
		while (hi < M - 1 && cat[hi] != cval)
			ihi();
		
		ans += (hi - lo + 1);
		if (cval != lval)
			ans -= np[cval][lval];
	}
	cout << ans << "\n";
	return 0;
}