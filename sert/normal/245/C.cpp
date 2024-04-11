#include <iostream>
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
typedef double db;

const ll inf = 1e9;
const ld eps = 1e-6;
const ll N = 1e6;
const ll M = 1e6;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}
string s;
int n, a[N], ans = 0;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 1 || n % 2 == 0){
        cout << "-1";
        return 0;
    }

    fr(i, n) cin >> a[i];

    int k = n / 2 - 1;
    int h;
    for(int i = k; i > 0; i--){
        h = max(a[i * 2 + 1], a[i * 2 + 2]);
        ans += h;
        a[i * 2 + 2] = 0;
        a[i * 2 + 1] = 0;
        a[i] = max(0, a[i] - h);
    }
    ans += max(max(a[0], a[1]), a[2]);
    cout << ans;
    return 0;
}