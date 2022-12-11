#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1234;
const int INF = 1e9;

string s, k;
bool u[N];
int ost, k0;

int main() {

    srand(3431);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0')
            k0++;
        else if (!u[s[i] - '0'] && (s[i] == '1' || s[i] == '6' || s[i] == '8' || s[i] == '9')) {
            u[s[i] - '0'] = true;
        } else {
            k += s[i];
            ost = (ost * 10 + s[i] - '0') % 7;
        }

    ost = (10000 * ost) % 7;
    ost = (7 - ost) % 7;

    cout << k;

    int a[4] = {1, 6, 8, 9};
    while (true) {
        random_shuffle(a, a + 4);
        if ((a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]) % 7 == ost) {
            cout << a[0] << a[1] << a[2] << a[3];
            for (int j = 0; j < k0; j++)
                cout << 0;
            return 0;
        }
    }

    //while(true);
}