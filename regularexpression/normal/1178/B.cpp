#include<algorithm>
#include<iostream>
#include<numeric>
#include<iomanip>
#include<cassert>
#include<chrono>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	ll a = 0, b = 0, c = 0;
	for (int i = 0; i < (int)s.size() - 1; ++i) {
		if (s[i] == 'v' && s[i + 1] == 'v') {
			++a;
			c += b;
		} else {
			if (s[i] == 'o') {
				b += a;
			}
		}
	}
	cout << c;
	return 0;
}