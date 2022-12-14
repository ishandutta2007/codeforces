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

const int N = (int) 1005, mod = (int) 0;
string s[N];
map<string, int> mark;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s[0] >> s[1];
    int n;
    cin >> n;
    cout << s[0] << ' ' << s[1] << endl;
    for (int j = 2; j < n + 2; ++j) {
        string t;
        cin >> t;
        mark[t] = 1;
        cin >> s[j];
        for (int i = 0; i < j + 1; ++i)
            if (!mark[s[i]])
                cout << s[i] << ' ';
        cout << endl;
    }
}