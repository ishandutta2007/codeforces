#include <bits/stdc++.h>

using namespace std;

int countone(int n) {
    int ans = 0;
    while (n > 0) {
        ++ans;
        n = ((n - 1) & n);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, p;
    cin >> n >> p;

    int ans = -1;
    for (int i = 1; i < 40; ++i) {
        n -= p;
        if (n < i) {
            break;
        }
        if (countone(n) <= i) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}