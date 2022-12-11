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

pint a[N], ans[N];
int n, len;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    n *= 2;
    fr(i, n){
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }

    sort(a, a + n);

    //fr(i, n) cerr << a[i].ff << " ";

    fr(i, n / 2){
        if (a[i * 2].ff != a[i * 2 + 1].ff)
            ret("-1");
        else ans[len++] = mp(a[i * 2].ss, a[i * 2 + 1].ss);
    }

    fr(i, len)
        cout << ans[i].ff << " " << ans[i].ss << "\n";

    return 0;
}