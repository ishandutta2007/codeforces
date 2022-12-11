#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k, len;
string s;

int main() {
    //reopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '4') {
            a[len++] = 2;
            a[len++] = 2;
            a[len++] = 3;
        } else if (s[i] == '6') {
            a[len++] = 3;
            a[len++] = 5;
        } else if (s[i] == '8') {
            a[len++] = 2;
            a[len++] = 2;
            a[len++] = 2;
            a[len++] = 7;
        } else if (s[i] == '9') {
            a[len++] = 2;
            a[len++] = 3;
            a[len++] = 3;
            a[len++] = 7;
        } else if (s[i] > '1')
            a[len++] = s[i] - '0';
    }

    sort(a, a + len);

    for (int i = len - 1; i >= 0; i--)
        cout << a[i];

    return 0;
}