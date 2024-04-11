#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

string s, t;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> s >> t >> n;
    cout << s << " " << t << endl;
    forn (i, n) {
        string a, b;
        cin >> a >> b;
        if (s == a) {
            s = b;
        } else {
            t = b;
        }
        cout << s << " " << t << endl;
    }
}