#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<int> lp(n), ls(n);
    vector<long long> sp(n), ss(n);

    lp[0] = a[0];
    sp[0] = 0;
    for (int i = 1; i < n; i++) {
        int v = max(a[i], lp[i - 1] + 1);
        sp[i] = sp[i - 1] + v - a[i];
        lp[i] = v;
    }

    ls[n - 1] = a[n - 1];
    ss[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        int v = max(a[i], ls[i + 1] + 1);
        ss[i] = ss[i + 1] + v - a[i];
        ls[i] = v;
    }

    long long mn = min(sp[n - 1], ss[0]);
    for (int i = 0; i < n; i++) {
        long long s = 0;
        int v = a[i];
        if (i > 0) {
            s += sp[i - 1];
            v = max(v, lp[i - 1] + 1);
        }
        if (i < n - 1) {
            s += ss[i + 1];
            v = max(v, ls[i + 1] + 1);
        }
        s += v - a[i];
        mn = min(mn, s);
    }

    cout << mn << endl;

    return 0;
}