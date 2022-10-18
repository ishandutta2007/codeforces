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
	int n, m;
	cin >> n >> m;
	if (n%2 == 0 || m%2 == 0)
		cout << (n*m)/2 << endl;
	else
		cout << (n*m-1)/2 << endl;
	return 0;
}