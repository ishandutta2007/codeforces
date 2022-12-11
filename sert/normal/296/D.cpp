#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define fr(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;
const ll M = 1e3 + 3;
const ll inf = 1e9+7;

using namespace std;

vector <ll> es[N];

priority_queue< pair<ll, ll> > q;
ll n, a[M][M], v[M], r[M][M], h, sum;
ll ans[M], len, pos[M];



int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    fr(i, n)
        fr(j, n){
            cin >> a[i][j];
            r[i][j] = inf;
        }

    fr(i, n){
        cin >> v[i];
        pos[v[i] - 1] = i;
    }

    for(int k = n - 1; k >= 0; k--){
        h = v[k] - 1;
        sum = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                a[i][j] = min(a[i][j], a[i][h] + a[h][j]);
                if (pos[i] >= k && pos[j] >= k)
                    sum += a[i][j];
            }
        ans[len++] = sum;
    }

    for(int i = len - 1; i >= 0; i--)
        cout << ans[i]  << " ";

    return 0;
}