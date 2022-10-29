#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#ifdef _DEBUG
#include <cassert>
#define ensure(expr) assert(expr);
#else
#define ensure(expr) (void)(expr)
#endif

const int MAXN = 1005000;

char s[MAXN], t[MAXN];
int n1, n2;
int sum_t[9][MAXN];

int
getVal(char c)
{
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    ensure(c == 'B');
    return 2;
}

int
main()
{
    scanf(" %s %s", s, t);
    n1 = strlen(s);
    n2 = strlen(t);
    long long res = 0ll;
    for (int i = 1; i <= n2; ++i) {
        for (int j = 0; j < 9; ++j) {
            sum_t[j][i] = sum_t[j][i - 1];
        }
        if (i != 1) {
            int new_pair = getVal(t[i - 2]) * 3 + getVal(t[i - 1]);
            sum_t[new_pair][i]++;
        }
    }
    int cur_da = 1, cur_db = 1;
    int cur_ca = 1, cur_cb = 1;
    for (int pos_b = 1; pos_b <= n1; ++pos_b) {
        while (cur_da < pos_b && cur_db <= n2) {
            if (s[cur_da - 1] == t[cur_db - 1]) {
                ++cur_db;
            }
            ++cur_da;
        }
        // cur_db is left border
        while (cur_ca <= pos_b && cur_cb <= n2) {
            if (s[cur_ca - 1] == t[cur_cb - 1]) {
                ++cur_ca;
            }
            ++cur_cb;
        }
        // cur_cb - 1 is right border
        //fprintf(stderr, "for pos_b = %d -> [%d, %d]\n", pos_b, cur_db, cur_cb - 1);
        int left_pos = cur_db;
        int right_pos = cur_cb - 1;
        res += max(right_pos - left_pos + 1, 0);
        if (right_pos >= left_pos && pos_b != 1 && s[pos_b - 1] != s[pos_b - 2]) {
            int new_pair = getVal(s[pos_b - 1]) * 3 + getVal(s[pos_b - 2]);
            res -= sum_t[new_pair][right_pos] - sum_t[new_pair][left_pos - 1];
        }
    }
    cout << res << '\n';
    return 0;
}