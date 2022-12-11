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

int a[N];
int main() {
    init();
    int n, k;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        k = 0;
        getline(cin, s);
        for (char ch: s)
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
                k++;
        if (k != a[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}