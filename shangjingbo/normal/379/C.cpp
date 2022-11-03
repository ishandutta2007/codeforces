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

const int maxn = 300000;

int n, a[maxn], id[maxn], answer[maxn];

bool byA(const int &i, const int &j)
{
    return a[i] < a[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
        id[i] = i;
    }
    sort(id, id + n, byA);
    long long sum = 0;
    int x = 0;
    for (int i = 0; i < n; ++ i) {
        x = max(a[id[i]], x + 1);
        answer[id[i]] = x;
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d ", answer[i]);
    }
    
    return 0;
}