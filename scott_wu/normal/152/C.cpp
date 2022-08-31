#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int N, M;
string blah[110];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> blah[i];
	
	ll ans = 1;
	for (int i = 0; i < M; i++)
	{
		bool has[26];
		for (int j = 0; j < 26; j++)
			has[j] = false;
		
		for (int j = 0; j < N; j++)
			has[blah[j][i]-'A'] = true;
		
		int cnt = 0;
		for (int j = 0; j < 26; j++)
			if (has[j]) cnt++;
		
		ans = (ans * cnt) % 1000000007LL;
	}
	cout << ans << "\n";
}