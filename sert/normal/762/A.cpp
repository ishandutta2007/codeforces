#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "dynasties"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;

vector <ll> d, o;
ll n, k;

int main() {
    //init();

    cin >> n >> k;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i) continue;
        d.push_back(i);
        if (i * i - n)
            o.push_back(n / i);
    }
    reverse(o.begin(), o.end());
    for (int i = 0; i < (int)o.size(); i++)
        d.push_back(o[i]);
    cout << (k > d.size() ? -1 : d[k - 1]);

    return 0;
}