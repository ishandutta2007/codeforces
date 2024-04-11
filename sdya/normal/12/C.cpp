#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int a[110];
map < string, int > MP;
vector < pair < int, string > > S;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	for (int i = 1; i <= m; i ++)
	{
		string s;
		cin >> s;
		MP[s] ++;
	}

	for (map < string, int > :: iterator it = MP.begin(); it != MP.end(); it ++)
		S.push_back(make_pair(it->second, it->first));
	sort(S.begin(), S.end());
	reverse(S.begin(), S.end());
	int res = 0;
	sort(a, a + n);
	for (int i = 0; i < S.size(); i ++)
		res += a[i] * S[i].first;
	printf("%d ", res);
	res = 0;
	reverse(a, a + n);
	for (int i = 0; i < S.size(); i ++)
		res += a[i] * S[i].first;
	printf("%d\n", res);
	return 0;
}