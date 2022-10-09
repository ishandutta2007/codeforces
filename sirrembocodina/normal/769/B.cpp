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

pair<int, int> a[100100];

int main() {
    int n;
    cin >> n;
    int sum = 0;
    forn (i, n) {
        cin >> a[i].fs;
        sum += a[i].fs;
        a[i].fs *= -1;
        a[i].sc = i;
    }
    if (sum < n - 1 || a[0].fs == 0) {
        cout << "-1\n";
        return 0;
    }
    cout << n - 1 << endl;
    sort(a + 1, a + n);
    forn (i, n) {
        a[i].fs *= -1;
    }
    int j = 0;
    for (int i = 1; i < n; ++i) {
        cout << a[j].sc + 1 << " " << a[i].sc + 1 << endl;
        --a[j].fs;
        if (a[j].fs == 0) {
            ++j;
        }
    }
    return 0;
}