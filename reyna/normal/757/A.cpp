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

const int N = (int) 1e5 + 5, mod = (int) 0;
int cnt[N], cn0[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string x = "Bulbasaur";
    int n = (int) x.size();
    for (char c : x)
        cn0[c]++;
    string s;
    cin >> s;
    for (char c : s) {
        cnt[c]++;
    }
    for (int j = 1e5 + 1; j >= 0; --j) {
        int flag = 1;
        for (int a = 0; a <= 256; ++a)
            if (cn0[a] * j > cnt[a])
                flag = 0;
        if (flag) {
            cout << j << endl;
            return 0;
        }
    }
}