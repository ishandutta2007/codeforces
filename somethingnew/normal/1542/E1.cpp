#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
int cfind(vector<int> a) {
    int c = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            if (i < j and a[i] > a[j])
                c++;
        }
    }
    return c;
}
void sl1() {
    int n = 6;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] = i + 1;
    }
    int res = 0;
    do {
        sort(all(b));
        do {
            if (a < b and cfind(a) > cfind(b)) {
                res++;
            }
        } while (next_permutation(all(b)));
    } while (next_permutation(all(a)));
    cout << res << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int mod;
    cin >> mod;
    vector<vector<int>> perecnt(n + 1, vector<int>(n * n));
    perecnt[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + i < n * n; ++j) {
            for (int k = 0; k <= i; ++k) {
                perecnt[i + 1][j + k] += perecnt[i][j];
                perecnt[i + 1][j + k] %= mod;
            }
        }
    }
    vector<vector<int>> cnt(n, vector<int>(n));
    for (int i = 1; i <= n; ++i) {
        for (int dist = 1; dist < n; ++dist) {
            vector<int> prefsum(n * n);
            prefsum[0] = perecnt[i][0];
            int res = 0;
            for (int j = 1; j < n * n; ++j) {
                prefsum[j] = prefsum[j - 1] + perecnt[i][j];
                prefsum[j] %= mod;
                if (j > dist) {
                    res += prefsum[j - dist - 1] * perecnt[i][j];
                    res %= mod;
                }
            }
            cnt[i - 1][dist] = res;
        }
    }
    int ans = 0;
    int mn = 1;
    for (int prefeq = 0; prefeq + 1 < n; ++prefeq) {
        for (int i = 0; i + prefeq < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ans += cnt[n - prefeq - 2][i - j] * mn;
                ans %= mod;
            }
        }
        mn *= n - prefeq;
        mn %= mod;
    }
    cout << ans;
}