#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

void ret(string s) {
    cout << s;
    exit(0);
}

int n, a[N];
int main() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    if (a[n - 1] == 0)
        ret("UP");
    if (a[n - 1] == 15)
        ret("DOWN");
    if (n == 1)
        ret("-1");
    if (a[n - 1] < a[n - 2])
        ret("DOWN");
    ret("UP");


    return 0;
}