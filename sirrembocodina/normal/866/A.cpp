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

int main() {
    ios::sync_with_stdio(false);
    int a;
    cin >> a;
    if (a == 1) {
        cout << "1 1\n1\n";
        return 0;
    }
    cout << (a - 1) * 2 << " 2\n1 2\n";
    return 0;
}