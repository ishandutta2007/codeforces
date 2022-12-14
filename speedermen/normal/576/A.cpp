#include <bits/stdc++.h>

using namespace std;

int const MaxN = 1010;
int const MOD = 1000000007;

int u[MaxN], nu[MaxN], n;
vector < int > ans;

int gcd(int i, int j) {
    return j != 0 ? gcd(j, i % j) : i;
}

int lcm(int i, int j) {
    return i / gcd(i, j) * j;
}

int main() {
    ios :: sync_with_stdio(false);
    cin >> n;
    u[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (u[i] == true) {
            continue;
        }
        for(int j = n; j >= 1; --j) {
            if(u[j] == 1 && lcm(i, j) <= n) {
                u[lcm(i, j)] = true;
            }
        }
        ans.push_back(i);
    }
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i > 0) {
           cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}