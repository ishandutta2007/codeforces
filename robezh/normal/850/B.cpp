#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18;
const int MAXN = (int)5e5 + 500;
const int E6 = (int)1e6;
const int MAXA = E6 + 500;


int n,x,y;
int num[MAXN], cnt[MAXA];
bool prime[MAXA];
ll psum[MAXA];

ll get(int k){
    ll tcnt = 0, res = 0;
    for(int i = k; i <= E6 + k; i += k){
        int l = i - k + max(1, k - x/y), r = i;
        l = min(l, E6 + 1), r = min(r, E6);
        tcnt += (cnt[r] - cnt[l-1]);
        res += 1LL * i * (cnt[r] - cnt[l-1]) - (psum[r] - psum[l-1]);
    }
    return res * y + (n - tcnt) * x;
}

int main(){
    scanf("%d%d%d", &n, &x, &y);
    fill(cnt, cnt + MAXA, 0);
    fill(psum, psum + MAXA, 0);
    fill(prime, prime + MAXA, 1);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        cnt[num[i]] ++;
        psum[num[i]] += num[i];
    }
    for(int i = 1; i <= (int)1e6; i++) cnt[i] += cnt[i-1], psum[i] += psum[i-1];
    ll minCost = INF;
    for(int gcd = 2; gcd <= E6; gcd++){
        if(!prime[gcd]) continue;
        for(int k = gcd * 2; k <= E6; k += gcd){prime[k] = 0;}
        minCost = min(minCost, get(gcd));
    }
    printf("%I64d", minCost);
}