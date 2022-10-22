#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;

#define N 100005

void work() {
    int i , n , k , x , ans = 0;
    cin >> n >> k;
    for (i = 0 ; i < n ; ++ i) {
        cin >> x;
        ans += (x <= 5 - k);
    }
    cout << ans / 3 << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}