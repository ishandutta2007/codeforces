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
#include <cctype>
using namespace std;
typedef long long LL;

const int N = 200005;
int n , k;

void work() {
    cin >> n >> k;
    printf("%d\n" , (6 * n - 1) * k);
    for (int i = 0 ; i < n ; ++ i) {
        printf("%d %d %d %d\n" , (6 * i + 1) * k , (6 * i + 2) * k , (6 * i + 3) * k , (6 * i + 5) * k);
    }
}

int main() {
    work();
    return 0;
}