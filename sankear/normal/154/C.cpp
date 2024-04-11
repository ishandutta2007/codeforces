#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

#define pb push_back

typedef long long ll;

const int maxn = 1000100;
const ll hx = (ll)(2e5 + 3);

int a[maxn], b[maxn], perm[maxn];
ll p[maxn], h[maxn];

bool cmp(int a, int b){
    return h[a] < h[b];
}

int main(){
    //freopen("rifleman.in", "r", stdin);
    //freopen("rifleman.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    p[0] = 1;
    for(int i = 1; i < n; i++){
        p[i] = p[i - 1] * hx;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
        h[a[i]] += p[b[i]];
        h[b[i]] += p[a[i]];
    }
    for(int i = 0; i < n; i++){
        perm[i] = i;
    }
    sort(perm, perm + n, cmp);
    ll ans = 0;
    int last = 0;
    for(int i = 1; i < n; i++){
        if(h[perm[i - 1]] != h[perm[i]]){
            ans += ((ll)(i - last) * (i - last - 1)) / 2;
            last = i;
        }
    }
    ans += ((ll)(n - last) * (n - last - 1)) / 2;
    for(int i = 0; i < m; i++){
        if(h[a[i]] - p[b[i]] == h[b[i]] - p[a[i]]){
            ans++;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}