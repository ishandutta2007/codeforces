#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

ll a[200100], b[200100];
multiset<ll> s;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << (n + 1) / 2 - 1 << endl;
    return 0;
}