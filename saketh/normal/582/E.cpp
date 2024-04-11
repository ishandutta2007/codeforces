#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, MLIM = 1 << 16;
const int func[4] = { 0b1111111100000000, 0b1111000011110000, 0b1100110011001100, 0b1010101010101010 };

void add(int &a, int b) { a = (a + (b + MOD) % MOD) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int res[512][MLIM], tail = 0;

void transform(int a, bool op, bool inv) {
    if (op) reverse(res[a], res[a] + MLIM);
    for (int sz = 2; sz <= MLIM; sz *= 2) {
        for (int i = 0; i < MLIM; i += sz) {
            for (int j = 0; j < sz / 2; j++)
                add(res[a][i+j+sz/2], (inv ? -1 : 1) * res[a][i+j]);
        }
    }
    if (op) reverse(res[a], res[a] + MLIM);
}

int convolve(int a, int b, bool op) {
    transform(a, op, false), transform(b, op, false);

    for (int i = 0; i < MLIM; i++)
        res[tail][i] = prod(res[a][i], res[b][i]);

    transform(a, op, true), transform(b, op, true);
    transform(tail, op, true);
    return tail++;
}

int put_sum(int a, int b) {
    for (int i = 0; i < MLIM; i++)
        add(res[a][i], res[b][i]);
    return a;
}

string expr;

int compute(int a, int b) {
    if (expr[a] == '(') {
        int i = a + 1;
        for (int ct = 1; ct > 0; i++) {
            if (expr[i] == '(') ct++;
            if (expr[i] == ')') ct--;
        }

        int lef = compute(a + 1, i - 2);
        int rig = compute(i + 2, b - 1);

        int ret = tail++;
        if (expr[i] == '|' || expr[i] == '?')
            put_sum(ret, convolve(lef, rig, false));
        if (expr[i] == '&' || expr[i] == '?')
            put_sum(ret, convolve(lef, rig, true));
        return ret;
    } else {
        char var = expr[a];
        if ('a' <= var && var <= 'd') {
            res[tail][func[var - 'a'] ^ 0xffff]++;
        }
        else if ('A' <= var && var <= 'D')
            res[tail][func[var - 'A']]++;
        else {
            for (int i = 0; i < 4; i++) {
                res[tail][func[i]]++;
                res[tail][func[i] ^ 0xffff]++;
            }
        }
        return tail++;
    }
}

int main() {
    cin >> expr;

    int idx = compute(0, expr.size() - 1);

    int N, a, b, c, d, r;
    cin >> N;
    vector<pair<int, bool>> constraints(N);
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d >> r;
        constraints[i] = make_pair(8 * a + 4 * b + 2 * c + d, r);
    }

    int ans = 0;
    for (int i = 0; i < MLIM; i++) {
        bool good = true;
        for (int j = 0; j < N; j++) 
            good &= ((i >> constraints[j].first)&1) == constraints[j].second;
        if (good) add(ans, res[idx][i]);
    }
    cout << ans << "\n";
}