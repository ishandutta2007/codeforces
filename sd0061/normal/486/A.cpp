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

LL n;

int main() {
    cin >> n;
    if (n & 1) {
        cout << (n >> 1) - n << endl;
    } else {
        cout << (n >> 1) << endl;
    }
    return 0;
}