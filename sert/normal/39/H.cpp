#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double ld;

int n;

int st[1000];

int from10(int x, int s) {
    int ans = 0, cur = 0;
    while (x) {
        ans = ans + st[cur++] * (x % s);
        x /= s;
    }
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    st[0] = 1;
    for (int i = 1; i < 11; i++)
        st[i] = st[i - 1] * 10;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++)
            cout << from10(i * j, n) << " ";
        cout << "\n";
    }

    return 0;
}