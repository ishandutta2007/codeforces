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
    int n;
    cin >> n;
    int cnt = 0;
    string x;
    cin >> x;
    while (n--) {
        string s = "", t = "", ss = "";;
        cin >> ss;
        for (int j = 0; j < 3; ++j)
            s += ss[j];
        for (int j = 5; j < 8; ++j)
            t += ss[j];
        if (s == x) cnt ^= 1;
        if (t == x) cnt ^= 1;
    }
    cout << (cnt == 0? "home": "contest");
}