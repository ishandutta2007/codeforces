#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

const int MAXN = 100500;

typedef long long ll;

int n;
int arr[MAXN];
ll res;
int cnt[MAXN];

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int ok = 0;
    for (int i = 1; i <= n; ++i) {
        ok += cnt[i] % 2;
    }
    if (ok != n % 2) {
        cout << 0 << '\n';
    } else {
        int bord = 0;
        while (bord < n && arr[bord + 1] == arr[n - bord]) ++bord;
        if (bord == n) { // all array is palindrome
            cout << 1ll * n * (n + 1) / 2 << '\n';
        } else {
            int len = (n + 1) / 2;
            int lpos = len + 1, rpos = n - len;
            int mid = 0;
            while (lpos > 1 && rpos < n && arr[lpos - 1] == arr[rpos + 1]) {
                ++mid;
                --lpos;
                ++rpos;
            }
            // [1; bord] <-> [n; n - bord + 1]
            // and [lpos; rpos] is palindrome
            for (int it = 0; it < 2; ++it) {
                for (int i = 1; i <= n; ++i) {
                    cnt[i] = 0;
                }
                for (int i = bord + 1; i < lpos; ++i) {
                    cnt[arr[i]]++;
                }
                int fail = 0;
                for (int i = rpos + 1; i <= n - bord; ++i) {
                    cnt[arr[i]]--;
                    if (cnt[arr[i]] == -1) {
                        ++fail;
                    }
                }
                int cur_pos = lpos - 1;
                if (fail != 0) {
                    if (n & 1) {
                        if (cnt[arr[(n + 1) / 2]] == -1) {
                            --fail;
                        }
                        cnt[arr[(n + 1) / 2]]++;
                    }
                    cur_pos = (n + 1) / 2;
                }
                while (fail > 0) {
                    ++cur_pos;
                    if (cnt[arr[cur_pos]] < 0 && cnt[arr[cur_pos]] >= -2) {
                        --fail;
                    }
                    cnt[arr[cur_pos]] += 2;
                }
                res += 1ll * (bord + 1) * (n - cur_pos + 1);
                reverse(arr + 1, arr + n + 1);
            }
            cout << res - 1ll * (bord + 1) * (bord + 1) << '\n';
        }
    }
    return 0;
}