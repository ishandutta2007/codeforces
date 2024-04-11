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
int n , a[N];
void work() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    sort(a , a + n);
    int res = 0;
    LL s = 0;
    for (int i = 0 ; i < n ; ++ i) {
        if (s <= a[i]) {
            ++ res;
            s += a[i];    
        }
    }
    cout << res << endl;
}
int main() {
    work();
    return 0;
}