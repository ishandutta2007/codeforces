#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
const int N = 100005;
const int M = 505;

void work() {
    int a , b;
    cin >> a >> b;
    cout << min(a , b) << ' ' << (max(a , b) - min(a , b)) / 2 << endl;
}

int main() {
    work();
    return 0;
}