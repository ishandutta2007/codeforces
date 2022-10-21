#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = (int)2e5 + 500;
typedef pair<ll, ll> P;

int n,a,b;
ll h[MAXN], p[MAXN], bsum = 0;
P ps[MAXN];

int main(){
    scanf("%d%d%d", &n, &a, &b);
    for(int i = 0; i < n; i++){
        scanf("%I64d%I64d", &h[i], &p[i]);
        ps[i].first = max(h[i] - p[i], 1LL * 0);
        ps[i].second = max((1LL << a) * h[i] - p[i], 1LL * 0);
        bsum += p[i];
    }
    if(b == 0){cout << bsum << endl; return 0;}

    sort(ps, ps+n, greater<P>());

    ll sum = 0;
    ll res = 0;
    for(int i = 0; i < b; i++) sum += ps[i].first;
    res = sum;
    for(int i = 0; i < b; i++){
        res = max(res, sum - ps[i].first + ps[i].second);
    }
    sum -= ps[b-1].first;
    for(int i = b; i < n; i++){
        res = max(res, sum + ps[i].second);
    }
    cout << bsum + res;
}