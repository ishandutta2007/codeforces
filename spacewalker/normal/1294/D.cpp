#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int q, x; scanf("%d %d", &q, &x);
    vector<ll> perSpace(x);
    set<ll> mexPerSpace;
    for (int i = 0; i < x; ++i) mexPerSpace.insert(i);
    for (int i = 0; i < q; ++i) {
        int a; scanf("%d", &a);
        mexPerSpace.erase(perSpace[a%x] * x + a%x);
        ++perSpace[a%x];
        mexPerSpace.insert(perSpace[a%x] * x + a%x);
        printf("%lld\n", *mexPerSpace.begin()); 
    }
}