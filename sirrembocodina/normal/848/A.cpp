#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 0) {
        cout << 'a' << endl;
        return 0;
    }
    char c = 'a';
    string s = "";
    while (n) {
        int i = 2;
        for (; i * (i - 1) / 2 <= n; i++);
        --i;
        n -= i * (i - 1) / 2;
        forn (j, i) {
            s += c;
        }
        ++c;
    }
    cout << s;
    return 0;
}