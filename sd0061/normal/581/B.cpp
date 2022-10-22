#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
const int N = 100005;
const int M = 505;
int n , a[N] , b[N];
void work() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    int mx = 0;
    for (int i = n ; i > 0 ; -- i) {
        if (a[i] > mx)
            b[i] = 0;
        else
            b[i] = mx + 1 - a[i];
        mx = max(mx , a[i]);
    }
    for (int i = 1 ; i <= n ; ++ i)
        cout << b[i] << endl;
}

int main() {
    work();
    return 0;
}