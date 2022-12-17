#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const long long mod = 998244353;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	bool asd = s[0] == s[(int)s.size() - 1];
	long long pos1, pos2;
	for(pos1 = 0; pos1 < s.size() && s[pos1] == s[0]; pos1 ++);
	for(pos2 = (int)s.size() - 1; pos2 >= 0 && s[pos2] == s[(int)s.size() - 1]; pos2 --);
	cout << (asd ? (pos1 + 1) * ((int)s.size() - pos2) : pos1 + s.size() - pos2) % mod << endl;
	
	return 0;
}