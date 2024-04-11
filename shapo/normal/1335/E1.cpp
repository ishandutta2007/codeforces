#include <bits/stdc++.h>

using namespace std;

const int MAXN = 222222;
const int MAXA = 222;

int arr[MAXN];
int sym_cnt[MAXA][MAXN]; // prefix counts

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        // fill sym_cnt with zero
        for (int sym = 1; sym <= 200; ++sym) {
            // Segments [0; i)
            // for i = 0 -> empty segment [0; 0)
            // for i = n -> whole array   [0; n)
            for (int i = 0; i <= n; ++i) {
                sym_cnt[sym][i] = 0;
            }
        }
        for (int sym = 1; sym <= 200; ++sym) {
            // sym_cnt[sym][0] is already 0
            for (int i = 1; i <= n; ++i) {
                // for segment [0; i)
                // [0; i) -> [0; i - 1) + [i - 1; i)
                sym_cnt[sym][i] = sym_cnt[sym][i - 1] + (arr[i - 1] == sym);
            }
            /* Another interpretation
             *
             * for (int i = 0; i < n; ++i) {
             *    // for segment [0; i + 1)
             *    // [0; i + 1) -> [0; i) + [i; i + 1)
             *    sym_cnt[sym][i + 1] = sym_cnt[sym][i] + (arr[i] == sym);
             * }
             */
        }
        int ans = 1;
        for (int sym = 1; sym <= 200; ++sym) {
            // Calculate all occurences of symbol `sym` in array
            // store all of them in `pos` vector
            vector<int> pos;
            for (int i = 0; i < n; ++i) {
                if (arr[i] == sym) {
                    pos.push_back(i);
                }
            }
            int l_idx = 0, r_idx = int(pos.size()) - 1;
            while (l_idx < r_idx) {
                int max_central = 0;
                //
                //  l - 1  l  l + 1 ... r - 1  r  r + 1
                //   ...  sym  ...  ...  ...  sym  ...
                //   Central block in segment [l + 1; r - 1], i.e. [l + 1; r)
                int l_c = pos[l_idx] + 1, r_c = pos[r_idx];
                for (int sym_c = 1; sym_c <= 200; ++sym_c) {
                    max_central = max(max_central,
                                      sym_cnt[sym_c][r_c] - sym_cnt[sym_c][l_c]);
                }
                int left_block_cnt = l_idx + 1;
                ans = max(ans, max_central + 2 * left_block_cnt);
                l_idx++;
                r_idx--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}