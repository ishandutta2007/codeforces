#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cctype>

using namespace std;

const int MAXN = 16777216;
int cnt[MAXN];

void
calc(int from, int to)
{
    if (from != to - 1) {
        int mid = (from + to) / 2;
        calc(from, mid);
        calc(mid, to);
        for (int i = mid, j = from; i < to; ++i, ++j) {
            cnt[i] += cnt[j];
        }
    }
}

int
main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    fill(cnt, cnt + MAXN, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int mask = 0;
        char cur_c;
        for (int j = 0; j < 3; ++j) {
            do {
                cin >> cur_c;
            } while (!isalpha(cur_c));
            mask |= (1 << (cur_c - 'a'));
        }
        cnt[mask]++;
    }
    calc(0, MAXN);
    int res = 0;
    for (int i = 0; i < MAXN; ++i) {
        cnt[i] = n - cnt[i];
        res ^= (cnt[i] * cnt[i]);
    }
    cout << res << '\n';
    return 0;
}