#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n;
vector<int> a;

void read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i;
}

int ans1, ans2;

void run() {
    ans1 = 0;
    sort(all(a));
    for (auto i : a)
        ans1 += i;

    int sum = ans1;
    int now = 0;

    for (int i = 0; i < n; i++) {
        sum -= a[i];
        ans1 += sum - a[i] * (n - i - 1);
        ans1 += a[i] * i - now;
        now += a[i];            
    }
    ans2 = n;
    //cout << ans1 << " " << ans2 << endl;
    int g = __gcd(ans1, ans2);
    ans1 /= g;
    ans2 /= g;
}

void write() {
    cout << ans1 << " " << ans2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}