#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define fab(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 1e3 + 7;

ll sum, n, t, a[N], l;

bool u[N];
bool use[N][N];
string s[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    fr(i, n){
        cin >> s[i];
        fr(j, s[i].length())
            u[s[i][j] - 'a'] = true;
        fab(j, 1, s[i].length() - 1)
            use[s[i][j - 1] - 'a'][s[i][j] - 'a'] = true;
    }

    fr(i, 26)
        if (!u[i]){
            cout << char('a' + i);
            return 0;
        }

    fr(i, 26)
        fr(j, 26)
            if (!use[i][j]){
                cout << char('a' + i) << char('a' + j);
                return 0;
            }

    return 0;
}