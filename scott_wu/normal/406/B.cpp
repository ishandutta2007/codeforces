#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
bool use[MAXN];
vector <int> res;

int main()
{
	scanf ("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int t;
		scanf ("%d", &t);
		
		use[t-1] = true;
	}
	
	int left = N;
	for (int i = 0; i < 1000000; i++)
		if (use[i] && !use[999999-i])
		{
			use[999999-i] = true;
			res.push_back (999999-i);
			left--;
		}
	
	for (int i = 0; i < 1000000; i++)
		if (left && !use[i])
		{
			use[i] = use[999999-i] = true;
			res.push_back (i);
			res.push_back (999999-i);
			left -= 2;
		}
	
	sort (res.begin(), res.end());
	
	printf ("%d\n", N);
	for (int i = 0; i < N; i++)
	{
		if (i)
			printf (" ");
		printf ("%d", res[i] + 1);
	}
	printf ("\n");
	return 0;
}