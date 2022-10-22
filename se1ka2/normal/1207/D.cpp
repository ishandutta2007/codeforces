#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll MOD = 998244353;

ll memo[300005];

ll fact(int n){
    if(n == 0) return 1;
    if(memo[n]) return memo[n];
    return memo[n] = (fact(n - 1) * n) % MOD;
}

int main()
{
    int n;
    cin >> n;
    int a[300004] {0}, b[300004] {0};
    P p[300004];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i], &b[i]);
        p[i] = P(a[i], b[i]);
    }
    p[n] = P(10000000, 100000000);
    int now;
    sort(a, a + n);
    ll ansa = 1;
    now = 1;
    for(int i = 0; i < n; i++){
        if(a[i] == a[i + 1]) now++;
        else{
            ansa = ansa * fact(now) % MOD;
            now = 1;
        }
    }
    sort(b, b + n);
    ll ansb = 1;
    now = 1;
    for(int i = 0; i < n; i++){
        if(b[i] == b[i + 1]) now++;
        else{
            ansb = ansb * fact(now) % MOD;
            now = 1;
        }
    }
    sort(p, p + n);
    ll ansp = 1;
    now = 1;
    for(int i = 0; i < n; i++){
        if(p[i].second > p[i + 1].second){
            ansp = 0;
            break;
        }
        if(p[i].first == p[i + 1].first && p[i].second == p[i + 1].second) now++;
        else{
            ansp = ansp * fact(now) % MOD;
            now = 1;
        }
    }
    cout << (fact(n) - ansa - ansb + ansp + MOD * 2) % MOD << endl;
}