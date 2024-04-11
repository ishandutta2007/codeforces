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
const ll M = 1e4;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int n, x, a[N], ans = 0, l, r;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> x;
    bool fnd = false;
    fr(i, n){
        cin >> a[i];
        if (a[i] == x)
            fnd = true;
    }
    if (!fnd){
        a[n++] = x;
        ans = 1;
    }
    sort(a, a + n);
    fr(i, n)
        if (a[i] == x) r = i;
    fr(i, n)
        if (a[i] == x){
            l = i;
            break;
        }
    int m = (n - 1) / 2;
    if (l <= m && r >= m){
        cout << ans;
        return 0;
    }
    while(l > m){
        n++;
        m = (n - 1) / 2;
        ans++;
        r++;
    }
    while(r < m){
        n++;
        r++;
        ans++;
        m = (n - 1) / 2;
    }
    cout << ans;
    return 0;
}