#include <bits/stdc++.h>
using namespace std;

const int N = 105;

map<int , int> H;

int SG(int mask) {
    if (H.count(mask)) {
        return H[mask];
    }
    set<int> p;
    for (int i = 1 ; i <= 30 ; ++ i) {
        bool flag = 0;
        int x = 0;
        for (int j = 1 ; j <= 30 ; ++ j) {
            if (mask >> j & 1) {
                if (j < i) {
                    x |= 1 << j;
                } else {
                    flag = 1;
                    x |= 1 << j - i;
                }
            }
        }
        if (x % 2 == 1) x -= 1;
        if (x != mask && flag) {
            p.insert(SG(x));
        }
    }
    int res = 0;
    while (p.count(res)) ++ res;
    return H[mask] = res;
}

int main() {
    int n;
    scanf("%d" , &n);
    map<int , int> mx;
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        for (int j = 2 ; j * j <= x ; ++ j) {
            if (x % j == 0) {
                int y = 0;
                while (x % j == 0) {
                    x /= j;
                    ++ y;
                }
                mx[j] |= 1 << y;
            }
        }
        if (x > 1) {
            mx[x] |= 2;
        }
    }
    H[0] = 0;
    int res = 0;
    for (auto &it : mx) {
        //cout << it.second << endl;
        res ^= SG(it.second);
    }
    puts(res ? "Mojtaba" : "Arpa");
}