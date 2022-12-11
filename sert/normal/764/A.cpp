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

    int n, m, z, ans = 0;
    cin >> n >> m >> z;
    for (int i = m; i <= z; i += m)
        if (i % n == 0)
            ans++;
    cout << ans;

    return 0;
}