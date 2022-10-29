#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 501;

int l1, l2;
int a[MAXN], b[MAXN];
int len[MAXN][MAXN];
int pnt[MAXN][MAXN];
int res[MAXN];

int
main()
{
    cin >> l1;
    for (int i = 1; i <= l1; ++i) {
        cin >> a[i];
    }
    cin >> l2;
    for (int i = 1; i <= l2; ++i) {
        cin >> b[i];
    }
    len[0][0] = 0;
    for (int i = 1; i <= l1; ++i) {
        len[i][0] = 0;
        int ind = 0;
        int best_val = 0;
        for (int j = 1; j <= l2; ++j) {
            len[i][j] = len[i - 1][j];
            if (a[i] == b[j]) { // using this fact in the following computations
                if (len[i][j] < best_val + 1) {
                    len[i][j] = best_val + 1;
                    pnt[i][j] = ind;
                }
            }
            if (b[j] < a[i] && len[i][j] > best_val) {
                best_val = len[i][j];
                ind = j;
            }
        }
    }
    int k = 0;
    int ind_ans = 0;
    for (int j = 1; j <= l2; ++j) {
        if (k < len[l1][j]) {
            k = len[l1][j];
            ind_ans = j;
        }
    }
    for (int cur_pos = k, i = l1, j = ind_ans; cur_pos >= 1; --cur_pos) {
        while (a[i] != b[j] || (pnt[i][j] == 0 && len[i][j] != 1)) {
            --i;
        }
        res[cur_pos] = a[i];
        j = pnt[i][j];
        --i;
    }
    cout << k << '\n';
    for (int i = 1; i <= k; ++i) {
        cout << res[i] << " ";
    }
    cout << '\n';
    return 0;
}