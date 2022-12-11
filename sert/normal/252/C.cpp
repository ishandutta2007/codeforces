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

int a[N];
bool u[N];
pint p[N];
ll n, m, k, l, r, h, ans = 0, tmp = 0, d;
string s, s1;

int main()
{
   //freopen("a.in", "r", stdin);
   //freopen("a.out", "w", stdout);

    cin >> n >> d;
    fr(i, n) cin >> a[i];
    a[n] = a[n - 1] + d + 2;

    fr(i, n - 1){
        l = i;
        r = n;
        while(r - l > 1){
            m = (r + l) / 2;
            if (a[m] - a[i] > d) r = m;
            else l = m;
        }
        //cerr << l << "\n";
        if (l - i < 2) continue;
        h = l - i - 1;
        ans += ((h + 1) * h) / 2;
    }
    cout << ans;
    return 0;
}