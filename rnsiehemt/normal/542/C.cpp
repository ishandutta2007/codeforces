#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

int N;
int a[205];
int seen[205];
ll len[205];
ll dist[205];
ll tmp[205];

int cyclestart; bool incycle;
void f(int i, ll d) {
    if (seen[i] == 2) {
        incycle = false;
    } else if (seen[i] == 1) {
        len[i] = d-tmp[i];
        dist[i] = 0;
        cyclestart = i;
        incycle = true;
    } else if (seen[i] == 0) {
        seen[i] = 1;
        tmp[i] = d;
        f(a[i], d+1);
        seen[i] = 2;
        len[i] = len[a[i]];
        if (incycle) {
            if (i == cyclestart) incycle = false;
            else dist[i] = 0;
        }
        else dist[i] = dist[a[i]]+1;
    }
}

ll gcd(ll a, ll b) {
    if (!b) return a;
    else return gcd(b, a%b);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) { scanf("%d", &a[i]); a[i]--; }
    for (int i = 0; i < N; i++) if (!seen[i]) f(i, 0);
    ll ans = len[0], min = *std::max_element(dist, dist+N);
    for (int i = 0; i < N; i++) ans = (ans * len[i]) / gcd(ans, len[i]);
    if (min > ans) ans = ((min+ans-1ll)/ans)*ans;
    printf("%lld\n", ans);
}