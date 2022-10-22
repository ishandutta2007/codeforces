#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 2000005;

int main() {
    int a , m;
    cin >> a >> m;
    set<int> hash;
    a %= m;
    while (1) {
        if (a == 0) {
            puts("Yes");
            return 0;
        }
        if (hash.count(a)) {
            puts("No");
            return 0;
        }
        hash.insert(a);
        a <<= 1 , a %= m;
    }
    return 0;
}