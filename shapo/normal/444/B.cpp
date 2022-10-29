#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100500;

int a[MAXN], b[MAXN];
int pos[MAXN];
int n, d;
vector< int > ids;

ll x;

int
get()
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> d >> x;
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        swap(a[i], a[get() % (i + 1)]);
    }
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        b[i] = i < d;
    }
    for (int i = 0; i < n; ++i) {
        swap(b[i], b[get() % (i + 1)]);
    }
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            ids.push_back(i);
        }
    }
    for (int i = 0, cur_num = 0; i < n; ++i) {
        double cur_val = cur_num * 1. / (i + 1), tp = cur_num;
        cur_num += b[i];
        bool ok = false;
        int ans = 0;
        for (int s = 0; s <= 500 && s < n; ++s) {
            if (pos[n - s] <= i && b[i - pos[n - s]]) {
                ok = true;
                ans = n - s;
                break;
            }
            tp *= (1 - cur_val);
        }
        if (!ok) {
            for (int j = 0; j < int(ids.size()) && ids[j] <= i; ++j) {
                ans = max(ans, a[i - ids[j]]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}