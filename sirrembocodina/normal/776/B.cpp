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

bool notp[100100];

int main() {
    for (int i = 2; i < 100100; ++i) {
        if (notp[i]) {
            continue;
        }
        for (int j = i + i; j < 100100; j += i) {
            notp[j] = true;
        }
    }
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n < 3) {
        cout << 1 << endl;
        forn (i, n) {
            cout << "1 ";
        }
        cout << endl;
        return 0;
    }
    cout << 2 << endl;
    forn (i, n) {
        cout << 1 + notp[i + 2] << " ";
    }
    cout << endl;
    return 0;
}