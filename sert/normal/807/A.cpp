#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
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

const int N = (int)2e3 + 34;
const ll md = (int)1e9 + 7;

int n;
int a[N], b[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] - b[i]) {
            cout << "rated\n";
            return 0;
        }
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (a[i] != b[n - i - 1]) {
            cout << "unrated\n";
            return 0;
        }
    }
    cout << "maybe\n";
    return 0;
}