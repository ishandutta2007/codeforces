#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

int n;
void work() {
    LL res = 0;
    cin >> n;    
    for (int i = 1 ; n ; ++ i) {
        int x = 9;
        for (int j = 1 ; j < i ; ++ j)
            x *= 10;
        x = min(x , n);
        res += (LL) x * i;
        n -= x;
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}