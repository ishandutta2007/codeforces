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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;

void work() {
    int n;
    scanf("%d",&n);
    int x = 1 , y = 1 , z = 0;
    while (n >= x) {
        n -= x;
        ++ y;
        x += y;
        ++ z;
    }
    cout << z << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}