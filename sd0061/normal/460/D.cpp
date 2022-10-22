#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 100005;

LL L , R , K;

void work() {
    cin >> L >> R >> K;
    if (R - L <= 6) {
        int m = R - L + 1;
        LL ans = 1LL << 60;
        for (int i = 0 ; i < 1 << m ; ++ i) {
            int sum = 0 ; LL XOR = 0;
            for (int j = 0 ; j < m ; ++ j)
                if (i >> j & 1) {
                    ++ sum;
                    XOR ^= (j + L);
                }
            if (1 <= sum && sum <= K)
                ans = min(ans , XOR);
        }
        cout << ans << endl;
        for (int i = 0 ; i < 1 << m ; ++ i) {
            int sum = 0 ; LL XOR = 0;
            for (int j = 0 ; j < m ; ++ j)
                if (i >> j & 1) {
                    ++ sum;
                    XOR ^= (j + L);
                }
            if (1 <= sum && sum <= K && ans == XOR) {
                cout << sum << endl;
                for (int j = 0 ; j < m ; ++ j)
                    if (i >> j & 1)
                        cout << (j + L) << ' ';
                break;
            }
        }
        return;
    }

    if (K == 1) {
        cout << L << endl << 1 << endl << L << endl;
        return;
    }
    if (K == 2) {
        cout << 1 << endl;
        cout << 2 << endl;
        if (L & 1)
            ++ L;
        cout << L << ' ';
        cout << L + 1 << ' ';
        return;
    }
    if (K >= 4) {
        cout << 0 << endl;
        cout << 4 << endl;
        if (L & 1)
            ++ L;
        cout << L << ' ';
        cout << L + 1 << ' ';
        cout << L + 2 << ' ';
        cout << L + 3 << ' ';
        return;
    }
    LL i , j , k;
    for (i = 1 ; i < 50 ; ++ i) {
        k = (1LL << i) - 1;
        if (L <= k && k <= R) {
            j = ((((L - 1) >> i) + 1) << i) + (1LL << (i - 1)) - 1;
            if (j + 1 <= R && j != k && j + 1 != k) {
                cout << 0 << endl << 3 << endl;
                cout << j << ' ';
                cout << j + 1 << ' ';
                cout << k << ' ';
                return;
            }
        }
    }
    cout << 1 << endl;
    cout << 2 << endl;
    if (L & 1)
        ++ L;
    cout << L << ' ';
    cout << L + 1 << ' ';
}

int main() {
    work();
    return 0;
}