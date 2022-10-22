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
typedef unsigned long long ULL;
const int N = 2005;

void work() {
    int n , m;
    cin >> n >> m;
    for (int d = 1 ; ; ++ d) {
        if (!n) {
            printf("%d\n" , d - 1);
            return;
        }
        -- n;
        if (d % m == 0)
            ++ n;
    }

}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}