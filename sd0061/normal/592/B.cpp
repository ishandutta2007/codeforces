#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef long long LL;

char g[10][10];

int main() {
    int n;
    cin >> n;
    n -= 2;
    cout << (LL)n * n << endl;
    return 0;
}