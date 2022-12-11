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
ll n, x;
bool u[N];
int cur;

int main() {
    //init();

    cin >> n;
    cur = n;
    while (n--) {
        cin >> x;
        u[x] = true;
        while (u[cur]) {
            cout << cur << " ";
            cur--;
        }
        cout << "\n";
    }
    return 0;
}