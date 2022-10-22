#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 1e9 + 7;
int p , K;
bool v[N];
int main() {
    cin >> p >> K;
    int res = 1;
    if (K == 0) {
        for (int i = 1 ; i < p ; ++ i)
            res = (LL)res * p % Q;
    } else {
        for (int i = 0 ; i < p ; ++ i) {
            if (!v[i]) {
                //cout << i << endl;
                int x = i , s = 0 , z = 1;
                while (!v[x]) {
                    v[x] = 1;
                    ++ s;
                    x = (LL)x * K % p;
                    z = (LL)z * K % p;
                }
                if (z < 2)
                    res = (LL)res * p % Q;
                
            }

        }
    }
    cout << res << endl;
    return 0;
}