#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

map<int, int> br;

int main()
{
	int n; cin >> n;
	int col = 0, maxh = 0;	
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (br.find(a) == br.end()) {br[a] = 0; col++;}
		br[a]++;
		maxh = max(maxh, br[a]);
	}
	cout << maxh << " " << col;
}