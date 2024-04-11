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
const int N = 2505;
const int M = 200005;

void work() {
    LL n;
    cin >> n;
    if (n & 1) {
        cout << n - 9 << ' ' << 9 << endl;
    } else {
        cout << n - 6 << ' ' << 6 << endl;
    }
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}