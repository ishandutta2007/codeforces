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
    cin >> n;
    int a[100];
    forn (i, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << a[n / 2];
}