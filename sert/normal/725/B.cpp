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
const int tme[6] = {3, 4, 5, 2, 1, 0};
int main() {
    init();
    string s;
    cin >> s;
    ll row;
    sscanf(s.c_str(), "%I64d", &row);
    row--;
    cout << 1 + row / 4 * 16 + row % 2 * 7 + tme[s.back() - 'a'];
    return 0;
}