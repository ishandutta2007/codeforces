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

int n;

int main() {
    //init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << (i % 2 ? "I love" : "I hate") << (i == n - 1 ? " it\n" : " that ");
    }


    return 0;
}