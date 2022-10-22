//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;

/*
3 1
1 0 0
*/


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    li a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;

    li c0 = 0, c1 = 0;
    while(c0 * (c0 - 1) / 2 < a00)
        c0++;

    while(c1 * (c1 - 1) / 2 < a11)
        c1++;

    if(a01 > 0 || a10 > 0) {
        c0 = max(c0, 1ll);
        c1 = max(c1, 1ll);
    }

    if(c0 * (c0 - 1) / 2 != a00 || c1 * (c1 - 1) / 2 != a11) {
        cout << "Impossible" << endl;
        return 0;
    }

    if(c0 == 0 && c1 == 0) {
        cout << "0" << endl;
        return 0;
    }


    string s = "";

    for(int i = 0; i < c0; i++)
        s += '0';

    for(int i = 0; i < c1; i++)
        s += '1';


    a01 -= c0 * c1;

    int i = c0;
    while(a01 != 0 && a10 != 0 && i < c0 + c1) {
        if(a01 < -c0) {
            swap(s[i], s[i - c0]);
            i++;
            a01 += c0;
            a10 -= c0;
            continue;
        }

        int j = i;
        while(j > 0 && s[j - 1] == '0' && a01 != 0 && a10 != 0) {
            swap(s[j], s[j - 1]);
            a01++;
            a10--;
            j--;
        }
        i++;
    }

    if(a01 != 0 || a10 != 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << s << endl;
}