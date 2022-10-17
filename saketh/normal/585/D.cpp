#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int INF = 1e9;

int N;
int val[25][3];

int lim(int p) {
    int res = 1;
    for (int i = 0; i < p; i++)
        res *= 3;
    return res;
}

ull put(unsigned int a, unsigned int b) {
    return (ull(a) << 32) + ull(b);
}

struct res {
    ull diff;
    int lynn, mask;
    res(ull _diff, int _lynn, int _mask) {
        diff = _diff, lynn = _lynn, mask = _mask;
    }
    bool operator<(const res& r) const {
        if (diff != r.diff) return diff < r.diff;
        return lynn > r.lynn;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> val[i][j];

    int FH = N / 2, SH = N - FH;

    int M1 = lim(FH);
    vector<res> poss;

    for (int m = 0; m < M1; m++) {
        int s[3] = {0, 0, 0}, tm = m;

        for (int i = 0; i < FH; i++) {
            for (int j = 0; j < 3; j++) {
                if (tm % 3 != j) 
                    s[j] += val[i][j];
            }
            tm /= 3;
        }

        poss.push_back( { put(s[0] - s[1], s[0] - s[2]), s[0], m } );
    }

    sort(poss.begin(), poss.end());

    int ans = -INF, m1, m2, M2 = lim(SH);

    for (int m = 0; m < M2; m++) {
        int s[3] = {0, 0, 0}, tm = m;

        for (int i = 0; i < SH; i++) {
            for (int j = 0; j < 3; j++) {
                if (tm % 3 != j) 
                    s[j] += val[FH + i][j];
            }
            tm /= 3;
        }

        ull match = put(s[1] - s[0], s[2] - s[0]);
        auto it = lower_bound(poss.begin(), poss.end(), res(match, INF, 0));

        if (it != poss.end() && it->diff == match && s[0] + it->lynn > ans) {
            ans = s[0] + it->lynn;
            m1 = it->mask;
            m2 = m;
        }
    }

    if (ans == -INF) {
        cout << "Impossible\n";
    } else {
        string str = "LMW";

        for (int i = 0; i < N; i++) {
            int ign;
            if (i < FH) {
                ign = m1 % 3;
                m1 /= 3;
            } else {
                ign = m2 % 3;
                m2 /= 3;
            }

            for (int j = 0; j < 3; j++) {
                if (j != ign) 
                    cout << str[j];
            }
            cout << "\n";
        }
    }
}