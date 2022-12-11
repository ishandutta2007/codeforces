#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef int ll;
const ll N = 1e6 + 7;

ll n, kol, len;
ll a[N], ans[N];
bool u[N];

int main() {

    //freopen("a.in", "r", stdin);

    cin >> n;
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        u[a[i]] = true;
    }

    for (int i = 1; i <= 1000000; i++) {
        if (u[i] && u[1000001 - i] && i <= 500000)
            kol++;
        if (u[i] && !u[1000001 - i])
            ans[len++] = 1000001 - i;
    }

    for (int i = 1; i <= 500000; i++)
    if (!u[i] && !u[1000001 - i]) {
        if (!kol)
            break;
        ans[len++] = i;
        ans[len++] = 1000001 - i;
        kol--;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);


    return 0;
}