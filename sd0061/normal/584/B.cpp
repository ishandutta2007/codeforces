#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
const int N = 20;
const int Q = 1e9 + 7;
typedef long long LL;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 1 , b = 1;
    for (int i = 0 ; i < n + n + n ; ++ i)
        a = (LL)a * 3 % Q;
    for (int i = 0 ; i < n ; ++ i)
        b = (LL)b * 7 % Q;
    cout << (a - b + Q) % Q << endl;
    return 0;
}