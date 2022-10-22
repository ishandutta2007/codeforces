#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;
const int N = 200005;
int n , a[N];
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    sort(a , a + n);
    int p = (n - 1) / 2;
    int res = 1 << 30;
    for (int i = 0 ; i <= p ; ++ i)
        res = min(res , a[n - (p - i) - 1] - a[i]);
    cout << res << endl;
    return 0;
}