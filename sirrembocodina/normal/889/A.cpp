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

int a[200100];
bool used[200100];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 1;
    forn (i, n) {
        cin >> a[i + 1];
        if (used[a[i + 1]]) {
            ++ans;
        } else {
            used[a[i + 1]] = true;
        }
    }
    cout << ans << endl;
    return 0;
}