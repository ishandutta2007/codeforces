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



int main() {
    //init();

    int a, b;
    cin >> a >> b;
    cout << (abs(a - b) <= 1 && a + b > 0 ? "YES" : "NO");

    return 0;
}