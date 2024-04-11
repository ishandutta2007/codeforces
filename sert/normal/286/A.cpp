#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int n, a[N], b[N];
int st, fn;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    if (n % 4 == 2 || n % 4 == 3) {
        cout << -1;
        return 0;
    }
    st = 0;
    fn = n - 1;
    int a0 = 1;
    int an = n;
    while (st <= fn) {
        if (st == fn) {
            a[st] = st + 1;
            st++;
        } else {
            a[st++] = a0 + 1;
            a[st++] = an;
            a[fn--] = an - 1;
            a[fn--] = a0;
            a0 += 2;
            an -= 2;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}