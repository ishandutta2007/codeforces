#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define FOR(i,a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++ i)

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;

const double EPS = 1e-8;
const double PI = acos(-1.0);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    
    int old = 0;
    int res = 0;
    while (a > 0) {
        res += a;
        old += a;
        a = old / b;
        old %= b;
    }
    
    printf("%d\n", res);
    
    return 0;
}