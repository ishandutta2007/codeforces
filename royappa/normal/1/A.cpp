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
	int n, m, a;
	cin >> n >> m >> a;
	cout << LL((n+a-1)/a)*LL((m+a-1)/a) << endl;
	return 0;
}