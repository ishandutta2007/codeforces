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
typedef double ld;
const ll N = 1e6+5;

string s;
ll a[N];
ll m, l, r;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    fr(i, s.length() - 1)
        a[i + 1] = a[i] + (s[i] == s[i + 1] ? 1 : 0);
    cin >> m;
    fr(i, m) {
        cin >> l >> r;
        cout << a[r - 1] - a[l - 1] << "\n";
    }





    return 0;
}