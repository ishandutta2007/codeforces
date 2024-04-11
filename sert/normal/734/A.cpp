#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
const int N = (int)1e6 + 34;
int n, k, ans, a[N];
int main() {
    init();
    int n;
    string s;
    cin >> n >> s;
    int k = 0;
    for (char ch: s) {
        if (ch == 'A')
            k++;
    }
    if (k * 2 == n)
        cout << "Friendship\n";
    else if (k * 2 < n)
        cout << "Danik\n";
    else
        cout << "Anton\n";
    return 0;
}