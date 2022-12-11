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
int a[100][100], b, ans = 0;
int mx, mn, len = 0, pos, n, k, h;
bool u[1000];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    pos = k - 1;
    fr(i, k){
        cin >> h;
        a[i][0] = h;
        u[h] = true;
    }
    fab(i, 1, n * k)
        if (!u[i]){
            pos++;
            if (pos == k){
                pos = 0;
                len++;
            }
            a[pos][len] = i;
        }
    fr(i, k){
        fr(j, n)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}