#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)50000 + 500;

ll gcd(ll x, ll y){
    return x == 0 ? y : gcd(y % x, x);
}

bool p[N];
int n;
ll now;
ll a, b;


int main(){
    fill(p, p + N, true);
    for(int i = 2; i < N; i++){
        if(p[i]) for(int j = i*2; j < N; j+=i) p[j] = false;
    }

    scanf("%d", &n);
    scanf("%I64d%I64d", &a, &b);
    now = a * b;
    for(int i = 1; i < n; i++){
        scanf("%I64d%I64d", &a, &b);
        now = gcd(now, a * b);
    }

    if(now == 1) return !printf("-1");
    ll now1 = gcd(a, now);

    if(now1 != 1){
        for(int i = 2; 1LL * i * i <= now1; i++){
            if(!p[i]) continue;
            if(now1 % i == 0) return !printf("%d\n", i);
        }
        return !printf("%I64d\n", now1);
    }
    ll now2 = gcd(b, now);
    for(int i = 2; 1LL * i * i <= now2; i++){
        if(!p[i]) continue;
        if(now2 % i == 0) return !printf("%d\n", i);
    }
    return !printf("%I64d", now2);

}