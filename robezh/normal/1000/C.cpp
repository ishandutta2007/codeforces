#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500;
typedef pair<ll, int> P;

int n;
ll a,b;
map<ll, int> L, R;
set<ll> T;
ll res[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%I64d%I64d", &a, &b);
        L[a] ++, R[b+1] ++;
        T.insert(a), T.insert(b), T.insert(a+1), T.insert(b+1);
    }
    ll las = 0;
    int now = 0;
    for(ll t : T){
        res[now] += t - las;
        now += L[t] - R[t];
        las = t;
    }
    for(int i = 1; i <= n; i++) printf("%I64d ", res[i]);
}