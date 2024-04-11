#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int MAXN = 200001;
bool bad[MAXN];
const int INF = 1000000000;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

pair<long long, long long> xgcd(int a, int b) {
    if (b == 0) {
        return {1, 0};
    }
    auto p = xgcd(b, a % b);
    long long x1 = p.first;
    long long y1 = p.second;
    // x1 * b + y1 * (a % b) = g
    // x1 * b + y1 * (a - (a / b) * b) = g
    // x1 * b + y1 * a - (a / b) * y1 * b = g
    // a * (y1) + b * (x1 - (a / b) * y1) = g
    return {y1, x1 - (a / b) * y1};
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        bad[x] = true;
    }

    vector<pair<int, int>> oks;
    for (int i = 1; i < m; i++) {
        if (!bad[i]) {
            oks.push_back({gcd(i, m), i});
        }
    }

    sort(oks.begin(), oks.end());

    vector<pair<int, int>> mx_path_to_gcd(m, {-1, -1});
    vector<int> mx_path(oks.size());
    vector<int> prv(m, -1);

    for (int i = 0; i < oks.size(); i++) {
        int b = oks[i].second;
        int cur_mx = 0;

        int j = 1;
        while (j * j <= b) {
            if (b % j == 0) {
                int g;

                g = j;
                if (mx_path_to_gcd[g].first != -1) {
                    if (mx_path_to_gcd[g].first + 1 > cur_mx) {
                        cur_mx = mx_path_to_gcd[g].first + 1;
                        prv[b] = mx_path_to_gcd[g].second;
                    }
                }

                g = b / j;
                if (mx_path_to_gcd[g].first != -1) {
                    if (mx_path_to_gcd[g].first + 1 > cur_mx) {
                        cur_mx = mx_path_to_gcd[g].first + 1;
                        prv[b] = mx_path_to_gcd[g].second;
                    }
                }
            }
            j++;
        }

        int gg = oks[i].first;
        if (mx_path_to_gcd[gg].first < cur_mx) {
            mx_path_to_gcd[gg] = {cur_mx, b};
        }

        mx_path[i] = cur_mx;
    }

    int best = -10;
    int end = -1;
    for (int i = 0; i < oks.size(); i++) {
        if (mx_path[i] > best) {
            best = mx_path[i];
            end = oks[i].second;
        }
    }

    vector<int> ans;
    while (end != -1) {
        ans.push_back(end);
        end = prv[end];
    }
    reverse(ans.begin(), ans.end());

//    for (int i : ans) {
//        cout << i << " ";
//    }
//    cout << endl;

    if (best == -10) {
        if (!bad[0]) {
            cout << 1 << endl << 0 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    if (bad[0]) {
        best++;
    } else {
        best += 2;
    }
    cout << best << endl;
    cout << ans[0] << " ";
    for (int i = 0; i + 1 < ans.size(); i++) {
        // ans[i] * k = ans[i + 1] (mod m)
        // ans[i] * k = ans[i + 1] - m * q
        // ans[i] * k + m * q = ans[i + 1]
        int mult = ans[i + 1] / gcd(ans[i], m);
        auto kq = xgcd(ans[i], m);
        long long k = kq.first % m * mult;
        cout << (k % m + m) % m << " ";
    }
    if (!bad[0]) {
        cout << 0 << endl;
    }

    return 0;
}