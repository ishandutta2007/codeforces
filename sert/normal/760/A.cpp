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


const ll md = (int)1e9 + 7;
const int N = 5002;

int q[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    //init();

    int m, d;
    cin >> m >> d;

    int x = q[m - 1] - (8 - d);

    cout << (x + 6) / 7 + 1;

    return 0;
}