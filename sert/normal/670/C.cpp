//made by Sert
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

ll a[N];
int n, k, p, t;
int b1 = -1, b2, l1, l2, ans;
int t1[N], t2[N];
string s;

map<int, int> m;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        m[p]++;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", t1 + i);
    for (int i = 0; i < n; i++) scanf("%d", t2 + i);
    for (int i = 0; i < n; i++) {
        l1 = m[t1[i]];
        l2 = m[t2[i]];
        if (l1 > b1 || (l1 == b1 && l2 > b2)) {
            b1 = l1;
            b2 = l2;
            ans = i + 1;
        }
    }
    cout << ans;
    return 0;
}