#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int LEN_MAX = 2e5 + 5;
const int MOD = 1e9 + 7;

int C[2][2];
int save_C[2][2];
long long factorial[LEN_MAX];
long long inv_fact[LEN_MAX];

long long mod_inv(long long a, long long m = MOD) {
    return a == 1 ? 1 : m - mod_inv(m % a, a) * m / a;
}

void precompute() {
    factorial[0] = inv_fact[0] = 1;

    for (int i = 1; i < LEN_MAX; i++) {
        factorial[i] = i * factorial[i - 1] % MOD;
        inv_fact[i] = mod_inv(i) * inv_fact[i - 1] % MOD;
    }
}

long long choose(int n, int r) {
    return factorial[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int &get_C(char first, char second) {
    return C[first - '0'][second - '0'];
}

long long remaining() {
    if (C[0][0] < 0 || C[0][1] < 0 || C[1][0] < 0 || C[1][1] < 0)
        return 0;

    if (C[0][1] < C[1][0] || C[0][1] > C[1][0] + 1)
        return 0;

    if (C[0][1] == 0)
        return C[1][1] == 0 ? 1 : 0;

    return choose(C[1][1] + C[0][1] - 1, C[1][1]) * choose(C[0][0] + C[1][0], C[0][0]) % MOD;
}

long long solve(string &N) {
    memcpy(save_C, C, sizeof(C));
    int total_length = C[0][0] + C[0][1] + C[1][0] + C[1][1] + 1;

    if (N == "0" || (int) N.size() < total_length)
        return 0;

    if ((int) N.size() > total_length) {
        N = "";

        for (int i = 0; i < total_length; i++)
            N += '1';
    }

    long long solutions = 0;

    for (int diff = 1; diff < total_length; diff++) {
        if (N[diff] == '1' && get_C(N[diff - 1], '0') > 0) {
            get_C(N[diff - 1], '0')--;
            solutions += remaining();
            get_C(N[diff - 1], '0')++;
        }

        get_C(N[diff - 1], N[diff])--;
    }

    if (C[0][0] == 0 && C[0][1] == 0 && C[1][0] == 0 && C[1][1] == 0)
        solutions++;

    memcpy(C, save_C, sizeof(C));
    return solutions % MOD;
}

void subtract_one(string &N) {
    int len = N.size();

    for (int i = len - 1; i >= 0; i--)
        if (N[i] == '1') {
            N[i] = '0';

            for (int j = i + 1; j < (int) N.size(); j++)
                N[j] = '1';

            return;
        }

    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    string A, B;
    cin >> A >> B >> C[0][0] >> C[0][1] >> C[1][0] >> C[1][1];
    subtract_one(A);
    cout << (solve(B) - solve(A) + MOD) % MOD << '\n';
}