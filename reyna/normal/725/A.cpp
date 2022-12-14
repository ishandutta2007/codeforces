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

const int N = (int) 0, mod = (int) 0;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string x;
    cin >> x;
    int res = 0;
    for (int i = 0; i < (int) x.size(); ++i)
        if (x[i] == '<')
            res++;
        else
            break;
    for (int i = (int) x.size() - 1; i >= 0; --i)
        if (x[i] == '>')
            res++;
        else
            break;
    cout << res << endl;
}