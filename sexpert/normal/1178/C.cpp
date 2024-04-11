#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
ll p2[5000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p2[0] = 1;
    for(int i = 1; i < 5000; i++)
        p2[i] = (p2[i - 1] + p2[i - 1])%MOD;

    int w, h;
    cin >> w >> h;
    cout << p2[w + h] << '\n';
}