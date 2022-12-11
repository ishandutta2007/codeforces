#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>

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
ll kol;
string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    fr(i, s.length())
        a[s[i] - 'a']++;
    fr(i, 26)
        if (a[i] % 2 == 1)
            kol++;
    if (kol == 0 || kol % 2 == 1) cout << "First";
    else cout << "Second";
    return 0;
}