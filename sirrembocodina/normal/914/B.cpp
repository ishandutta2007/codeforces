#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forn2(i, n) for (i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[100100];
int cnt[100100];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a, a + n);
    forn (i, n) {
        if (cnt[a[i]] % 2) {
            cout << "Conan\n";
            return 0;
        }
    }
    cout << "Agasa";
    return 0;
}