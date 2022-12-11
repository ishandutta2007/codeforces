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
#define pint pair <long long, long long>
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

int b[N];
bool u[N];
pint p[N], a[N];
ll n, m, k, l, r, h, ans = 0, tmp = 0, len = 1;
string s, s1;

bool cmp(pint a, pint b){
    return a.ss < b.ss;
}

int main()
{
   //freopen("a.in", "r", stdin);
   //freopen("a.ot", "w", stdout);

    cin >> n;
    fr(i, n){
        cin >> p[i].ff;
        b[i] = p[i].ff;
        p[i].ss = i;
    }

    sort(p, p + n);
    a[0] = p[0];
    fab(i, 1, n - 1){
        if (p[i].ff != p[i - 1].ff)
            a[len++] = p[i];
    }
    sort(a, a + len, cmp);
    //cerr << len << "\n";
    //fr(i, len) cerr << a[i].ff << " ";
    if (len == 2){
        ll a1 = a[0].ff;
        ll a2 = a[1].ff;
        if (n == 2) ret("-1");
        if (b[0] == b[n - 1])
        {
            if (n == 3) ret("-1");
            int pos = 1;
            while(b[pos] == b[0]){
                pos++;
                if (pos == n)
                    ret("-1");
            }
            if (b[pos] == b[pos + 1]){
                cout << pos << " " << pos + 1 << "\n";
            }
            else
            {
                if (pos == n - 2)
                    cout << n - 2 << " " << n - 1 << "\n";
                else
                    cout << pos + 1 << " " << pos + 2 << "\n";
            }
            return 0;
        }
        if (b[1] != b[0])
        {
            cout << "1 2";
            return 0;
        }
        else
        {
            cout << "2 " << n;
            return 0;
        }
        return 0;
    }
    if (len < 3) ret("-1");
        if ((a[1].ff - a[0].ff) * (a[2].ff - a[1].ff) < 0)
            cout << a[0].ss + 1 << " " << a[2].ss + 1;
        else
            cout << a[0].ss + 1 << " " << a[1].ss + 1;

    return 0;
}