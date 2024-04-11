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


int main() {
    init();

    string a, b, s, t;
    int n;
    cin >> a >> b;
    cout << a + " " + b << "\n";
    cin >> n;
    while (n--) {
        cin >> s >> t;
        if (s == a) a = t;
        else b = t;
        cout << a + " " + b << "\n";
    }

    return 0;
}