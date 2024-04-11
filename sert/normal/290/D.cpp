#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>

#define fr(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;

using namespace std;

ll n, m, x, y, a[N], b[N];
string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    fr(i, s.length())
        if (s[i] > 'z' || s[i] < 'a')
            s[i] = s[i] + 'e' - 'E';
    cin >> n;
    fr(i, s.length())
        if (s[i] < 'a' + n && s[i] >= 'a')
            s[i] = s[i] + 'E' - 'e';
    cout << s;
    //cerr << int('a');
    return 0;
}