#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, k;
int cnt[2];
int mv[2];
int sum;

int
solve()
{ // 1 - stannis, 0 - daenerys
    if (mv[0] + mv[1] == 0) {
        return sum == 0;
    }
    int id = 0;
    while (mv[0] + mv[1] != 1) {
        if (id == 0) {
            if (cnt[0]) {
                --cnt[0];
            } else {
                --cnt[1];
                sum ^= 1;
            }
            --mv[0];
        } else {
            --mv[1];
            if (cnt[1]) {
                --cnt[1];
                sum ^= 1;
            } else {
                --cnt[0];
            }
        }
        id = 1 - id;
    }
    if (id == 0) {
        return (cnt[sum] > 0); 
    }
    return cnt[sum ^ 1] == 0;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    mv[0] = (n - k + 1) / 2;
    mv[1] = (n - k) / 2;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        val %= 2;
        sum ^= val;
        cnt[val]++;
    }
    sum ^= 1;
    int ans = solve();
    cout << ((ans) ? "Stannis" : "Daenerys") << '\n';
    return 0;
}