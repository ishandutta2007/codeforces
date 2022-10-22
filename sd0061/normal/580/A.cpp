#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , a[N];
int main() {
    scanf("%d" , &n);
    int res = 1 , x = 1;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        if (i && a[i] >= a[i - 1])
            ++ x;
        else
            x = 1;
        res = max(res , x);
    }
    cout << res << endl;
    return 0;
}