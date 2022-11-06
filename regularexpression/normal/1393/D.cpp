#include<bits/stdc++.h>
using namespace std;

int n, m;
char A[2020][2020];
int Li[2020][2020], Lj[2020][2020];
int Ri[2020][2020], Rj[2020][2020];
int up[2020][2020], down[2020][2020];
int L[2020][2020], R[2020][2020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            Li[i][j] = 1;
            if (i > 0 && A[i][j] == A[i - 1][j])
                Li[i][j] += Li[i - 1][j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            Ri[i][j] = 1;
            if (i + 1 < n && A[i][j] == A[i + 1][j])
                Ri[i][j] += Ri[i + 1][j];
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            Lj[i][j] = 1;
            if (j > 0 && A[i][j] == A[i][j - 1])
                Lj[i][j] += Lj[i][j - 1];
        }
    }
    for (int j = m - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            Rj[i][j] = 1;
            if (j + 1 < m && A[i][j] == A[i][j + 1])
                Rj[i][j] += Rj[i][j + 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            up[i][j] = 1;
            if (i > 0 && A[i][j] == A[i - 1][j])
                up[i][j] = max(up[i][j], min({Lj[i][j], Rj[i][j], up[i - 1][j] + 1}));
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            down[i][j] = 1;
            if (i + 1 < n && A[i][j] == A[i + 1][j])
                down[i][j] = max(down[i][j], min({Lj[i][j], Rj[i][j], down[i + 1][j] + 1}));
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            L[i][j] = 1;
            if (j > 0 && A[i][j] == A[i][j - 1])
                L[i][j] = max(L[i][j], min({Li[i][j], Ri[i][j], L[i][j - 1] + 1}));
        }
    }
    for (int j =m - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            R[i][j] = 1;
            if (j + 1 < m && A[i][j] == A[i][j + 1])
                R[i][j] = max(R[i][j], min({Li[i][j], Ri[i][j], R[i][j + 1] + 1}));
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            ans += min({up[i][j], down[i][j], L[i][j], R[i][j]});
    }
    cout << ans;
    return 0;
}