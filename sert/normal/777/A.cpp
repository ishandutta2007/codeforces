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

const string s[6] = {"012", "102", "120", "210", "201", "021"};

int main() {
    init();

    int n, x;
    cin >> n >> x;
    cout << s[n % 6][x];

    return 0;
}