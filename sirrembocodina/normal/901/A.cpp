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
    int n;
    cin >> n;
    ++n;
    bool was = false;
    forn (i, n) {
        cin >> a[i];
        if (a[i] > 1 && i && a[i - 1] > 1) {
            was = true;
        }
    }
    if (!was) {
        cout << "perfect\n";
        return 0;
    }
    int ind = 0;
    cout << "ambiguous\n";
    forn (i, n) {
        forn (j, a[i]) {
            if (i && a[i - 1] > 1 && j == 0) {
                cout << ind - 1 << " ";
            } else {
                cout << ind << " ";
            }
        }
        ind += a[i];
    }
    cout << endl;
    ind = 0;
    forn (i, n) {
        forn (j, a[i]) {
            cout << ind << " ";
        }
        ind += a[i];
    }
    cout << endl;
    return 0;
}