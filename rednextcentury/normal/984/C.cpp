#include <bits/stdc++.h>
#define readFile freopen("in.txt","r",stdin)
#define writeFile freopen("qqq.txt","w",stdout)
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

const int N = 100010;

#define ll long long

int main() {
#ifndef ONLINE_JUDGE
    readFile;
#endif
    fastIO;
    int n; scanf("%d", &n);
    while(n--){
        ll q,p,b; scanf("%I64d%I64d%I64d", &q, &p, &b);
        ll d = __gcd(q,p);
        q /= d;
        p /= d;
        ll x = __gcd(p,b);
        while(x != 1){
            p /= x;
            x = __gcd(p,x);
        }
        if(p == 1) puts("Finite");
        else puts("Infinite");
    }
    return 0;
}