#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int n, m, mx = 0;
vector <int> odd, ev;
vector <int> bad;
bool u[N];
set <int> s;

int cur_odd = 1;
int cur_even = 2;
int ans;

int get_next_odd() {
    ans++;
    while (u[cur_odd]) cur_odd += 2;
    u[cur_odd] = true;
    mx = max(mx, cur_odd);
    return cur_odd;
}

int get_next_even() {
    ans++;
    while (u[cur_even]) cur_even += 2;
    u[cur_even] = true;
    mx = max(mx, cur_even);
    return cur_even;
}

int num_odd;
int num_even;
int a[N];

int main() {
    init();

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        if (s.find(a[i]) != s.end()) {
            bad.push_back(i);
            continue;
        }
        s.insert(a[i]);
        if (a[i] % 2 == 0)
            ev.push_back(i);
        else
            odd.push_back(i);
        if (a[i] < N)
            u[a[i]] = true;
    }

    num_odd = odd.size();
    num_even = ev.size();

    while (odd.size() > n / 2) {
        a[odd.back()] = get_next_even();
        odd.pop_back();
        num_odd--;
        num_even++;
    }

    while (ev.size() > n / 2) {
        a[ev.back()] = get_next_odd();
        ev.pop_back();
        num_even--;
        num_odd++;
    }

    for (int p: bad) {
        if (num_even == n / 2) {
            a[p] = get_next_odd();
            num_odd++;
        } else {
            a[p] = get_next_even();
            num_even++;
        }
    }

    if (mx > m) {
        cout << -1;
        return 0;
    }

    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}