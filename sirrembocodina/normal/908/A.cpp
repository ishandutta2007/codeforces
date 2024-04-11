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

int a[100100];

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int ans = 0;
    forn (i, s.size()) {
        if (s[i] == 'a' ||
            s[i] == 'e' ||
            s[i] == 'u' ||
            s[i] == 'i' ||
            s[i] == 'o' ||
            s[i] == '1' ||
            s[i] == '3' ||
            s[i] == '5' ||
            s[i] == '7' ||
            s[i] == '9') {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}