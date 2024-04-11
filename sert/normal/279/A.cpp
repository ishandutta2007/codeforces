#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <deque>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define pint pair <int, int>
#define vint vector <int>
#define vpint vector < pair <int, int> >
#define ff first
#define ss second
#define cpr(n) cout.precision(n);

typedef long long ll;
typedef long double ld;

const ll inf = 1e9+7;
const ld eps = 1e-9;
const ll N = 1e6+5;
const ll M = 1e3+5;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

ll a[N], n, k, m, t, x, y;
bool u[N];
string s, s1, s2;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> x >> y;

    n = 0;

    if (x == y && y == 0)
        ret("0");

    if (x + y >= 0 && y > x){
        cout << y * 4 - 2;
        return 0;
    }

    if (x + y < 0 && y >= x){
        cout << (-x) * 4 - 1;
        return 0;
    }

    if (x + y <= 1 && x > y){
        cout << (-y) * 4;
        return 0;
    }

    cout << x * 4 - 3;

    return 0;
}