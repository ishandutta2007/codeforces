#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    s += '.';
    t += '.';

    vector<vector<vector<int>>> minl(n + 1, vector<vector<int>>(m + 1, vector<int>(n + m + 2, INF)));
    vector<vector<vector<int>>> preo(n + 1, vector<vector<int>>(m + 1, vector<int>(n + m + 2, 0)));
    minl[0][0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k < n + m + 2; ++k) {
                if (k + 1 < n + m + 2) {
                    if (minl[i][j][k + 1] > minl[i][j][k]) {
                        minl[i][j][k + 1] = minl[i][j][k] + 1;
                        preo[i][j][k + 1] = 0;
                    }
                    if (s[i] == '(' && minl[i + 1][j][k + 1] > minl[i][j][k]) {
                        minl[i + 1][j][k + 1] = minl[i][j][k] + 1;
                        preo[i + 1][j][k + 1] = 1;
                    }
                    if (t[j] == '(' && minl[i][j + 1][k + 1] > minl[i][j][k]) {
                        minl[i][j + 1][k + 1] = minl[i][j][k] + 1;
                        preo[i][j + 1][k + 1] = 2;
                    }
                    if (s[i] == '(' && t[j] == '(' && minl[i + 1][j + 1][k + 1] > minl[i][j][k]) {
                        minl[i + 1][j + 1][k + 1] = minl[i][j][k] + 1;
                        preo[i + 1][j + 1][k + 1] = 3;
                    }
                }
                if (k > 0) {
                    if (s[i] == ')' && minl[i + 1][j][k - 1] > minl[i][j][k]) {
                        minl[i + 1][j][k - 1] = minl[i][j][k] + 1;
                        preo[i + 1][j][k - 1] = 1;
                    }
                    if (t[j] == ')' && minl[i][j + 1][k - 1] > minl[i][j][k]) {
                        minl[i][j + 1][k - 1] = minl[i][j][k] + 1;
                        preo[i][j + 1][k - 1] = 2;
                    }
                    if (s[i] == ')' && t[j] == ')' && minl[i + 1][j + 1][k - 1] > minl[i][j][k]) {
                        minl[i + 1][j + 1][k - 1] = minl[i][j][k] + 1;
                        preo[i + 1][j + 1][k - 1] = 3;
                    }
                }
            }
        }
    }

    int ans = INF;
    int ansk = 0;
    for (int k = 0; k < n + m + 2; ++k) {
        if (ans > minl[n][m][k] + k) {
            ans = minl[n][m][k] + k;
            ansk = k;
        }
    }

    int ansi = n, ansj = m;
    string anss = "";
    while (ansi > 0 || ansj > 0 || ansk > 0) {
        if (preo[ansi][ansj][ansk] == 0) {
            anss += '(';
        }
        else if (preo[ansi][ansj][ansk] == 1) {
            anss += s[ansi - 1];
            --ansi;
        }
        else if (preo[ansi][ansj][ansk] == 2) {
            anss += t[ansj - 1];
            --ansj;
        }
        else {
            anss += s[ansi - 1];
            --ansi;
            --ansj;
        }
        if (anss.back() == '(') {
            --ansk;
        }
        else {
            ++ansk;
        }
    }
    reverse(anss.begin(), anss.end());
    while (anss.size() < ans) {
        anss += ')';
    }

    cout << anss << "\n";

    return 0;
}