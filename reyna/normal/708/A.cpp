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
    string s;
    cin >> s;
    int st = 0;
    while (st < (int) s.size() && s[st] == 'a')
        ++st;
    if (st == s.size())
        s[st - 1] = 'z';
    while (st < (int) s.size() && s[st] != 'a')
        s[st]--, ++st;
    cout << s << endl;




}