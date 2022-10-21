#include <bits/stdc++.h>
using namespace std;

const int N = (int)1005, mod = 998244353;
typedef long long ll;

int w, h;
ll res = 1;

int main() {
    cin >> w >> h;
    for(int i = 0; i < w + h; i++) res = (res * 2) % mod;
    cout << res << endl;
}