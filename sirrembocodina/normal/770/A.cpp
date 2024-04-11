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

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    forn (i, n) {
        cout << char(i % k + 'a');
    }
    cout << endl;
}