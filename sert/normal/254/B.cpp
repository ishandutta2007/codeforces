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

const ll inf = 1e9;
const ld eps = 1e-9;
const ll N = 1e6;
const ll M = 1e3;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

ll a[N], ans[N];
ll n, len, mo[22], m, d, p, t;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    mo[0] = 0;
    mo[1] = 31;
    mo[2] = 59;
    mo[3] = 90;
    mo[4] = 120;
    mo[5] = 151;
    mo[6] = 181;
    mo[7] = 212;
    mo[8] = 243;
    mo[9] = 273;
    mo[10] = 304;
    mo[11] = 334;
    mo[12] = 365;
    cin >> n;
    fr(i, n){
        cin >> m >> d >> p >> t;

        d = d + mo[m - 1] + 365;
        fab(j, d - t, d - 1)
            a[j] += p;

    }

    int mx = 0;
    fr(i, N)
        if (a[i] > a[mx])
            mx = i;
    cout << a[mx];

    return 0;
}