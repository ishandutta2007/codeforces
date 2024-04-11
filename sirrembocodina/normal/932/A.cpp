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
    string s;
    cin >> s;
    cout << s;
    forn (i, s.size()) {
        cout << s[s.size() - i - 1];
    }
    return 0;
}