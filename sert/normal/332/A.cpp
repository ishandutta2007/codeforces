#include <iostream>
#include <cmath>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;
const ld eps = 1e-8;
const ll md = 1e9 + 9;
const ll inf = 2e18 + 34;

using namespace std;

ll n, m, k, p, t, h;
ll a[N], b[N];
string s, s1, s2;
bool u[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    cin >> s;

    bool ok;

    fr(i, s.length()){
        if (i % n == 0 && i > 2)
            if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3])
                k++;
    }

    cout << k;

    return 0;
}