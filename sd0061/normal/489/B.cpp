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

int n , m;
int a[N] , b[N];
void work () {
    int i , j , res = 0;
    cin >> n;
    for (i = 0 ; i < n ; ++ i)
        cin >> a[i];
    sort(a , a + n);
    cin >> m;
    for (j = 0 ; j < m ; ++ j)
        cin >> b[j];
    sort(b , b + m);
    for (i = j = 0 ; i < n ; ++ i) {
        while (j < m && a[i] - b[j] > 1)
            ++ j;
        if (abs(a[i] - b[j]) < 2)
            ++ res , ++ j;
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}