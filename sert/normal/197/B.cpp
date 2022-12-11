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

ll gcd(ll a, ll b){
    ll c = a % b;
    while(c != 0){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

string s;
ll n, m, r, ans;
ll aa, bb;
ll a[N], b[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    n++;
    m++;
    fr(i, n) cin >> a[i];
    fr(i, m) cin >> b[i];
    aa = a[0];
    bb = b[0];
    if (n != m){
        if (n > m){
            if (aa * bb < 0)
                cout << "-";
            cout << "Infinity";

        }
        else cout << "0/1";
        return 0;
    }
    if (aa * bb < 0) cout << "-";
    aa = abs(aa);
    bb = abs(bb);
    ll nod = gcd(aa, bb);
    cout << aa / nod << "/" << bb / nod;
    return 0;
}