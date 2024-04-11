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
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 100<<10;
char str[SIZE];

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i<n; i++)
    	if (str[i] == '0') {
    		for (int j = 0; j<i; j++) printf("%c", str[j]);
    		for (int j = i+1; j<n; j++) printf("%c", str[j]);
    		printf("\n");
			return 0;
    	}
    str[n-1] = 0;
	printf("%s\n", str);
	
	return 0;
}