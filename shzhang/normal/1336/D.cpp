#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <map>

using namespace std;

#define ll long long

ll tricnt, strcnt;
int n;
int ans[105];
map<int, int> diff2old;

pair<ll, ll> query(int tile)
{
    printf("+ %d\n", tile);
    fflush(stdout);
    ll na, nb;
    scanf("%lld%lld", &na, &nb);
    pair<ll, ll> retv = make_pair(na - tricnt, nb - strcnt);
    tricnt = na; strcnt = nb;
    return retv;
}

int main()
{
    scanf("%d", &n);
    scanf("%lld%lld", &tricnt, &strcnt);
    for (int i = 3; i <= 105; i++) {
        diff2old[(i * (i-1) * (i-2) - (i-1) * (i-2) * (i-3)) / 6] = i-1;
    }

    if (n % 4 == 2) {
        query(n - 2);
    } else if (n % 4 == 3) {
        query(n - 3);
    }
    int lastprod = 0;
    for (int i = 1; i <= n; i += 4) {
        if (i + 3 <= n) {
            pair<ll, ll> a = query(i+2);
            pair<ll, ll> b = query(i);
            pair<ll, ll> c = query(i+1);
            pair<ll, ll> d = query(i);
            if (b.first == 0 && d.first == 0) {
                ans[i] = 0;
            } else if (b.first == 0) {
                ans[i] = 1;
            } else {
                ans[i] = diff2old[b.first];
            }
            if (i == 1) {
                ans[i+2] = d.second - b.second - 1;
                ans[i+1] = b.second / (ans[i+2]+1);
                ans[i+3] = (c.second / (ans[i+2]+1)) - ans[i] - 1;
            } else {
                ans[i+2] = d.second - b.second - 1 - ans[i-1];
                ans[i+1] = (b.second - (ans[i-2]+1)*ans[i-1]) / (ans[i-1] + ans[i+2] + 1);
                ans[i+3] = ((c.second - ans[i-1]*(ans[i]+1)) / (ans[i+2]+1)) - ans[i] - 1;
            }
            lastprod = a.second - ans[i] * ans[i+1] - ans[i+1] * ans[i+3];
        } else if (i == n) {
            pair<ll, ll> pr = query(i-1);
            ans[i] = (pr.second - (ans[i-3]+1)*(ans[i-2]+1)) / (ans[i-2]+1);
        } else if (i + 1 == n) {
            pair<ll, ll> pr = query(i);
            ans[i+1] = (pr.second / ans[i-1]) - ans[i-2] - 1;
            ans[i] = lastprod / ans[i-1];
        } else {
            pair<ll, ll> a = query(i);
            pair<ll, ll> b = query(i+1);
            ans[i] = lastprod / ans[i-1];
            ans[i+2] = (b.second / (ans[i] + 1)) - ans[i-1];
            ans[i+1] = (a.second - (ans[i-2]+1)*ans[i-1]) / (ans[i-1]+ans[i+2]);
        }
        //printf("%d %d %d %d\n", ans[i], ans[i+1], ans[i+2], ans[i+3]);
    }
    //printf("lastprod %d\n", lastprod);
    if (n % 4 == 2) {
        ans[n-2]--;
    } else if (n % 4 == 3) {
        ans[n-3]--;
    }
    printf("! ");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n"); fflush(stdout);
    return 0;
}