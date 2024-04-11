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
const int INF = 1e9 + 34;

string s;
int n;
bool u[N];

void ex() {
    cout << "NO\n";
    exit(0);
}

int main() {
    init();

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        u[s[i] - '0'] = true;

    if (!u[7] && !u[0] && !u[9]) ex();
    if (!u[1] && !u[2] && !u[3]) ex();
    if (!u[1] && !u[4] && !u[7] && !u[0]) ex();
    if (!u[3] && !u[6] && !u[9] && !u[0]) ex();
    cout << "YES\n";


    return 0;
}