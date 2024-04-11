#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
const int N = 20;
typedef long long LL;
using namespace std;

int main() {
    int n , t;
    cin >> n >> t;
    if (t < 10) {
        for (int i = 0 ; i < n ; ++ i)
            cout << t;
    } else {
        if (n == 1)
            cout << -1;
        else {
            cout << 1;
            for (int i = 1 ; i < n ; ++ i)
                cout << 0;
        }
    }
    return 0;
}