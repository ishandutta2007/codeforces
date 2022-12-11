#include <iostream>
#include <cmath>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;
const ld eps = 1e-8;
const ll md = 1e9 + 9;
const ll inf = 2e18 + 34;

using namespace std;

ll n, m, k, p, t, h, mn, num, sum, sm, n2, n1;
ll a[N], b[N], c[N];
string s, s1, s2;
bool u[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;
    fr(i, n) cin >> a[i];
    b[0] = a[0];
    for(int i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i];
    c[0] = b[k - 1];
    for(int i = 1; i < n - k + 1; i++)
        c[i] = c[i - 1] - a[i - 1] + a[i + k - 1];

    sm = c[0] + c[k];
    num = 0;
    n2 = k;
    mn = c[0];

    for(int i = 1; i < n - 2 * k + 1; i++){
        if (c[i] > c[num]){
            mn = c[i];
            num = i;
        }
        if (c[i + k] + c[num] > sm){
            n1 = num;
            n2 = i + k;
            sm = c[i + k] + c[num];
        }
    }

    cout << n1 + 1 << " " << n2 + 1 << "\n";


    return 0;
}