#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

typedef long long LL;


int main() {
	// your code goes here
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		int len = s.size();
		if (len <= 10)
			cout << s;
		else
			cout << s[0] << len-2 << s[len-1];
		cout << endl;
	}
	return 0;
}