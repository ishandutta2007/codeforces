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

string s;
int n, m, r, ans;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    fr(i, n){
        cin >> s;
        if (s.length() == 1 && s[0] >= '0' && s[0] <= '9') ans++;
        if (s.length() == 2 && s[0] == '1' && s[1] >= '0' && s[1] <= '7') ans++;
        //ABSINTH, BEER, BRANDY, CHAMPAGNE, GIN, RUM, SAKE, TEQUILA, VODKA, WHISKEY, WINE
        if (s == "ABSINTH") ans++;
        if (s == "BEER") ans++;
        if (s == "BRANDY") ans++;
        if (s == "CHAMPAGNE") ans++;
        if (s == "GIN") ans++;
        if (s == "RUM") ans++;
        if (s == "SAKE") ans++;
        if (s == "TEQUILA") ans++;
        if (s == "VODKA") ans++;
        if (s == "WHISKEY") ans++;
        if (s == "WINE") ans++;
    }

    cout << ans;
    return 0;
}