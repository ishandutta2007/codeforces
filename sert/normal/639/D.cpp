#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5 + 34;
const ll md = 1e9 + 34;
const ll INF = 3e18 + 20;

ll n, b, c, k;
ll a[N];
queue<ll> q[6];
ll sum[10], ca;
ll lst, x;
ll num, ps, mx, d;
ll ans = INF;

ll getd(int st, int fn) {
    return ((fn - st) / 5) * b + ((fn - st) % 5) * c;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d%I64d%I64d%I64d", &n, &k, &b, &c);

    b = min(b, c * 5);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", a + i);
        a[i] += 1000000005;
    }
    sort(a, a + n);

    for (int ost = 0; ost < 5; ost++) {
        for (int i = 0; i < 5; i++) {
            sum[i] = 0;
            while (!q[i].empty())
                q[i].pop();
        }
        lst = ost - 5;
        num = 0;

        for (int i = 0; i < n; i++) {
            ca = 0;

            x = a[i];
            while (x % 5 != ost) {
                x++;
                ca += c;
            }
            for (int j = 0; j < 5; j++) {
                sum[j] += ((x - lst) / 5) * b * q[j].size();
            }
            lst = x;


            if (num + 1 >= k) {

                while (num + 1 > k) {
                    ps = -1;
                    mx = -1;
                    for (int j = 0; j < 5; j++) {
                        if (q[j].empty())
                            continue;
                        d = getd(q[j].front(), x);
                        if (d > mx) {
                            mx = d;
                            ps = j;
                        }
                    }
                    sum[ps] -= getd(q[ps].front(), x);
                    q[ps].pop();
                    num--;
                }

                for (int j = 0; j < 5; j++)
                    ca += sum[j];

                ans = min(ans, ca);
                /*if (ans == -20) {
                    cout << ost << " " << i << "\n";
                }*/
            }

            q[a[i] % 5].push(a[i]);
            sum[a[i] % 5] += getd(a[i], x);
            num++;

        }
    }

    cout << ans;


    return 0;
}