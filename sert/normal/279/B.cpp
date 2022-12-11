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

ll a[N], n, k, m, t, x, y, ans, ta;
string s, s1, s2;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> t;

    fr(i, n)
        cin >> a[i];
    a[n] = 1e18;

    ll u = 0;
    ll sum = 0;
    while (sum + a[u] <= t){
        sum += a[u++];
        ta = u;
        ans = u;
    }

    fab(i, 1, n - 1){
        sum -= a[i - 1];
        ta--;
        if (sum < 0) sum = 0;
        if (ta < 0) ta = 0;
        if (u < i) u = i;
        while(sum + a[u] <= t){
            sum += a[u++];
            ta++;
        }
        ans = max(ans, ta);
    }

    cout << ans;
    return 0;
}