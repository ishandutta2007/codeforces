#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e7 + 34;
const ll M = (ll)1e9 + 34;

int sum(int x) {
    return (x < 10 ? x : x % 10 + sum(x / 10));
}

int f[N];

int main() {
    ll x;
    vector <int> v;

    for (int i = 1; v.size() < 34; i++) {
        f[i] = sum(i);
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                f[i] = sum(j) + f[i / j];
                if (f[i] == sum(i))
                    v.push_back(i);
                break;
            }
        }
    }

    int n;
    cin >> n;
    cout << v[n - 1];

    return 0;
}