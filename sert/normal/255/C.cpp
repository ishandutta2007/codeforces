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

int num[N + 3], len;
short int b[M][M];
int a[N + 3], h1, h2, n, k, pos;
bool fnd;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    //cerr << sizeof(short int) << " " << sizeof(int);
    cin >> n;
    fab(j, 1, 1000000)
        num[j] = -1;
    fr(i, n){
        cin >> k;
        a[i] = k;
        if (num[k] == -1)
            num[k] = len++;
    }

    fr(i, n){
        pos = num[a[i]];
        fr(j, len){
            if (pos == j){
                b[j][j]++;
                continue;
            }
            if (b[pos][j] % 2 == 0)
                b[pos][j]++;
            if (b[j][pos] % 2 == 1)
                b[j][pos]++;
        }
    }

    int mxi = 0, mxj = 0;

    fr(i, len)
        fr(j, len)
            if (b[i][j] > b[mxi][mxj]){
                mxi = i;
                mxj = j;
            }
    cout << b[mxi][mxj];

    return 0;
}