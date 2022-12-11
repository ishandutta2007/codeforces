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

ll n, a[N];
bool u[N];
string s, s1, s2;
ll ans, kol, k, h;
ll find(ll x){
    ll l, r, m;
    l = 0;
    r = n;
    while (r - l > 1){
        m = (l + r) / 2;
        if (a[m] > x)
            r = m;
        else
            l = m;
    }
    if (a[l] != x)
        return -1;
    return l;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;
    if (k == 1){
        cout << n;
        return 0;
    }
    ans = n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);

    int i = 0;
    while (i < n)
        if (!u[i])
        {
            u[i] = true;
            kol = 1;
            h = find(a[i] * k);
            while (h != -1){
                u[h] = true;
                h = find(a[h] * k);
                kol++;
            }
            ans -= kol / 2;
            i++;
        }
        else
            i++;

    cout << ans;

    return 0;
}