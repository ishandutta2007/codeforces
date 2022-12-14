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

const int N = 1 << 9, mod = 0;
int match[N][N];
void s(int x) { match[x][x] = 1; }
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    match['b']['d'] = 1;
    match['d']['b'] = 1;
    s('A');
    s('H');
    s('I');
    s('M');
    s('O');
    s('o');
    s('T');
    s('U');
    s('V');
    s('v');
    s('W');
    s('w');
    s('X');
    s('x');
    s('Y');
    match['p']['q'] = match['q']['p'] = 1;
    string x;
    cin >> x;
    int flag = 1;
    for (int i = 0; i < (int) x.size(); ++i)
        if (!match[x[i]][x[(int) x.size() - i - 1]])
            flag = 0;
    cout << (flag? "TAK": "NIE");



}