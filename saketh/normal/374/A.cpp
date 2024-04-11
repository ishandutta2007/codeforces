#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N, M, i, j, A, B;

bool stuck = false;

int check(int dx, int dy) {
    if (stuck) return (dx == 0 && dy == 0 ? 0 : INF);

    if (dx < 0) dx *= -1;
    if (dy < 0) dy *= -1;

    if (dx % A || dy % B) return INF;

    int m1 = dx / A, m2 = dy / B;

    if (m1 % 2 != m2 % 2) return INF;

    return max(m1, m2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M >> i >> j >> A >> B;

    // can we make a move at all??
    if (i - 1 < A && N - i < A) stuck = true;
    if (j - 1 < B && M - j < B) stuck = true;

    int ans = INF;

    ans = min(ans, check(1 - i, M - j));
    ans = min(ans, check(N - i, 1 - j));
    ans = min(ans, check(N - i, M - j));
    ans = min(ans, check(1 - i, 1 - j));

    if (ans == INF) cout << "Poor Inna and pony!\n";
    else cout << ans << "\n";
}