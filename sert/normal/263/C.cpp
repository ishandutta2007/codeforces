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

int n, m, h, k, p, v1, v2;
int ans;
int a[N][5];
int len[N];
string s;
bool fnd, q, u[N];

bool reb(int v1, int v2){
    bool fd = false;
    for(int i = 0; i < 4; i++)
        if (a[v1][i] == v2)
            fd = true;
    return fd;
}

bool go(int pr, int v, int kol){

    u[v] = true;

    if (fnd)
        return true;

    if (kol == n){
        if (reb(v, 1) && reb(pr, 1)){
            fnd = true;
            cout << v << " ";
            return true;
        }
        return false;
    }

    for(int i = 0; i < 4; i++){
        if (reb(pr, a[v][i]) && !u[a[v][i]])
            if (go(v, a[v][i], kol + 1)){
                cout << v << " ";
                //fnd = true;
                return true;
            }
    }


    u[v] = false;
    return false;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    fr(i, n + n){
        cin >> v1 >> v2;
        a[v1][len[v1]++] = v2;
        a[v2][len[v2]++] = v1;
    }

    u[1] = true;

    for(int i = 0; i < 4; i++){
        if (!fnd)
            q = go(1, a[1][i], 2);
    }

    if (!fnd)
        cout << "-1";
    else
        cout << "1";

    return 0;
}