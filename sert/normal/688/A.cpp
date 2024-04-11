#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif

    string one, s;
    int n, k, lst = 0, ans = 0, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        one.push_back('1');
    for (int i = 0; i < d; i++) {
        cin >> s;
        if (s == one) {
            ans = max(ans, i - lst);
            lst = i + 1;
        }
    }

    cout << max(ans, d - lst);

    return 0;
}