#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

char ch;
set <char> s;
long long n, a[345656], ans;

int main() {
    //freopen("a.in", "r", stdin);
    for (int i = 0; i < 5; i++) {
        cin >> n;
        ans += n;
    }
    printf("%I64d\n", (ans == 0 || ans % 5 ? -1 : ans / 5));
    return 0;
}