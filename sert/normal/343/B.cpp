#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

ll a[N];
ll n, k, p, t, h;
string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;

    n = 0;
    fr(i, s.length()) {
        a[n++] = s[i];
        while (true) {
            if (n < 2) break;
            if (a[n - 1] != a[n - 2]) break;
            n -= 2;
        }
    }
    if (n != 0)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}