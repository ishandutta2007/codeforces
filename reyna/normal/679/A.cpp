// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = 0, mod = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cnt = 0;
    for (int i = 2; i <= 50; ++i) {
        int pr = 0, flag = 0;
        int x = i;
        for (int j = 2; j <= i; ++j) {
            if (x % j == 0) {
                while (x % j == 0) {
                    x /= j;
                    flag++;
                }
                pr++;
            }
        }
        if (pr == 1 && flag <= 2) {
            cout << i << endl;
            string res;
            cin >> res;
            if (res == "yes")
                cnt++;
        }
    }
    if (cnt <= 1) {
        cout << "prime" << endl;
    } else {
        cout << "composite" << endl;
    }





}