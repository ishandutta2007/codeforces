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
    int k, a, b;
    cin >> k >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    if (b < k) {
        if (a % k) {
            cout << "-1\n";
        } else {
            cout << a / k << endl;
        }
        return 0;
    }
    cout << a / k + b / k;
    return 0;
}