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

const int N = 1e6 + 34;
const ll md = (ll)1e9 + 7;

bool u[N];

int main() {
    init();

    string s;
    int k, c = 0;
    cin >> s >> k;
    int n = s.length();

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') c++;
        if (c == k) {
            cout << n - i - k;
            return 0;
        }
    }

    cout << n - 1;

    return 0;
}