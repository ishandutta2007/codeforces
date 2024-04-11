#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A, B, l, t, m;
int n;

ll nth(ll i) {return A + B * (i - 1);}

ll find(ll st, ll ed) {
    if(st >= ed) return st;
    ll mid = st + ed >> 1;
    ll val = (nth(l) + nth(mid + 1)) * (mid + 2 - l) / 2;
    if(val <= t * m) return find(mid + 1, ed);
    else return find(st, mid);
}

int main() {
    scanf("%I64d%I64d%d", &A, &B, &n);
    while(n --) {
        scanf("%I64d%I64d%I64d", &l, &t, &m);
        if(t < A + B * (l - 1)) {puts("-1"); continue;}
        printf("%I64d\n", find(l, (t - A) / B + 1));
    }
}