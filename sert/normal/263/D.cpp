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

int n, m, k, v1, v2, len, h;
int num[N], ans[N];
vector <int> es[N];
bool u[N];

void dfs(int v){
    int mn = N;
    bool wa = false;
    num[v] = ++len;
    ans[len] = v;
    u[v] = true;

    for(int i = 0; i < es[v].size(); i++){
        h = es[v][i];
        if (!u[h]){
            dfs(h);
            wa = true;
        }
        else{
            mn = min(mn, num[h]);
        }
    }

    if (!wa){
        cout << len - mn + 1 << "\n";
        for(int i = mn; i <= len; i++)
            cout << ans[i] << " ";
        exit(0);
    }

}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m >> k;
    fr(i, m){
        cin >> v1 >> v2;
        es[v1].pb(v2);
        es[v2].pb(v1);
    }

    dfs(1);

    return 0;
}