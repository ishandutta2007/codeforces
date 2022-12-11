#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
string s[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    ll kol = 0, sum = 0, nk;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == "halfplus") {
            sum += kol * p + p / 2;
            kol = kol * 2 + 1;
        } else {
            sum += kol * p;
            kol = kol * 2;
        }
    }

    cout << sum;


    return 0;
}