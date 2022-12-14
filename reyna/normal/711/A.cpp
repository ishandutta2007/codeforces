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

const int N = 1005, mod = 0;
string s[N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < 2 && !flag; ++j)
            if (s[i][j * 3] == 'O' && s[i][j * 3 + 1] == 'O') {
                s[i][j * 3] = '+';
                s[i][j * 3 + 1] = '+';
                flag = 1;
            }
    }
    if (!flag) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << s[i] << '\n';





}